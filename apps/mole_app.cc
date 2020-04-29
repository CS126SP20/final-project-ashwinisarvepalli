// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "mole_app.h"

#include <cinder/app/App.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include <gflags/gflags.h>

#include <cinder/Font.h>
#include <cinder/Text.h>
#include <cinder/Vector.h>

#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <string>

namespace myapp {
using cinder::Color;
const size_t kLimit = 3;
const char kDbPath[] = "mole.db";

using cinder::app::KeyEvent;
using namespace ci;
using namespace ci::app;

DECLARE_string(name);
DECLARE_uint32(tilesize);
DECLARE_uint32(size);

MyApp::MyApp()
  :  player_name{FLAGS_name},
     engine{FLAGS_size, FLAGS_size, FLAGS_tilesize},
     game_state{GameState::kPlaying},
     tile_size{FLAGS_tilesize},
     draw_tile_speed{0.5605},
     song_name{"Eye of the Tiger"},
     length_of_game{0},
     my_image{gl::Texture2d::create(loadImage( loadAsset( "cosmic.jpg")))},
     tile_image{gl::Texture::create(loadImage( loadAsset( "piano.jpg")))},
     leaderboard{cinder::app::getAssetPath(kDbPath).string()} {}


void MyApp::setup() {
  cinder::audio::SourceFileRef b_src =
      cinder::audio::load(cinder::app::loadAsset("tiger.mp3"));
  background_voice = cinder::audio::Voice::create(b_src);
  background_voice->start();
}

void MyApp::update() {
  if (game_state == GameState::kGameOver || !background_voice->isPlaying()) {
    if (top_players.empty() || personal_highs.empty()) {
      leaderboard.AddScoreToLeaderBoard(
          {player_name, engine.GetScore()}, song_name);
      top_players = leaderboard.RetrieveHighScores(kLimit, song_name);
      personal_highs = leaderboard.RetrieveHighScores(
          {player_name, engine.GetScore()}, kLimit, song_name);
      // It is crucial the this vector be populated, given that `kLimit` > 0.
      assert(!top_players.empty());
    }
    return;
  }
}

template <typename C>
void PrintText(const std::string &text, const C &color, const cinder::ivec2 &size,
               const cinder::vec2 &loc) {
  cinder::gl::color(color);
  auto box = cinder::TextBox()
      .alignment(cinder::TextBox::CENTER)
      .font(cinder::Font("Arial", 25))
      .size(size)
      .color(color)
      .backgroundColor(cinder::ColorA(0, 0, 0, 0))
      .text(text);
  const auto box_size = box.getSize();
  const cinder::vec2 locp = {loc.x - box_size.x / 2, loc.y - box_size.y / 2};
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);
  cinder::gl::draw(texture, locp);
}

void MyApp::draw() {
  cinder::gl::enableAlphaBlending();
  if (game_state == GameState::kGameOver) {
    if (!printed_game_over)
      cinder::gl::clear(Color::black());
    background_voice->stop();
    DrawGameOver();
    return;
  }
  cinder::gl::clear();
  DrawBackground();
  current_time = ci::app::getElapsedSeconds();
  DrawTile();
  if ((current_time - start_time) > draw_tile_speed) {
    engine.Step();
    start_time = current_time;
  }
  DrawScore();
}

void MyApp::DrawBackground() const {
  cinder::gl::draw(my_image, getWindowBounds());
}

void MyApp::DrawTile() const {
  Color::white();
  const mole::Location loc = engine.GetTile().GetLocation();
  cinder::gl::draw(tile_image, Rectf(tile_size * loc.Row(),
                                     tile_size * loc.Col(),
                                     tile_size * loc.Row() + tile_size,
                                     tile_size * loc.Col() + tile_size));
}

void MyApp::DrawScore() {
  const std::string text = std::to_string(engine.GetScore());
  const Color color = Color::white();
  const cinder::ivec2 size = {250, 30};
  const cinder::vec2 loc = {110, 70};
  PrintText("Score: " + text, color , size, loc);
}

void MyApp::DrawGameOver() {
  if (printed_game_over)
    return;
  if (top_players.empty() || personal_highs.empty())
    return;
  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {600, 30};
  const Color color = Color::white();
  size_t row = 0;
  PrintText("Game Over :(", color, size, {center.x, center.y - (++row) * 250});
  //print the high scores
  PrintText("High Scores: ", color, {400, 40},
            {center.x, center.y - (++row) * 90});
  for (const mole::Player &player : top_players) {
    std::stringstream ss;
    ss << song_name << " - " << player.name << " - " << player.score;
    PrintText(ss.str(), color, size, {center.x, center.y - (++row) * 30});
  }
  //print the personal high scores
  size_t row2 = 0;
  PrintText("Personal Highs: ", color, {400, 40},
            {center.x, center.y});
  for (const mole::Player &player : personal_highs) {
    std::stringstream ss;
    ss << song_name << " - " << player.name << " - " << player.score;
    PrintText(ss.str(), color, size, {center.x, center.y + (++row2) * 30});
  }
  printed_game_over = true;
}

void MyApp::mouseDown(MouseEvent event) {
  //event.isRight() || event.isLeft() || event.isMiddle()
  if (event.isLeft()) {
    //call engine funtion that will check is mouse pos is within the tile bounds
    if(!engine.MouseInTile(event.getX(), event.getY())) {
      game_state = GameState::kGameOver;
    }
  }
  if (event.isLeft() && event.isAltDown()) {
    ResetGame();
  }
}

void MyApp::ResetGame() {
  engine.Reset();
  printed_game_over = false;
  game_state = GameState::kPlaying;
  top_players.clear();
  personal_highs.clear();
  current_time = 0;
  start_time = 0;
}

}  // namespace myapp
