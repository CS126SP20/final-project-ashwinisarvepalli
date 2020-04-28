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
     draw_tile_speed{1.7999},
     length_of_game{0},
     my_image{gl::Texture2d::create(loadImage( loadAsset( "cosmicbg.jpg")))},
     leaderboard{cinder::app::getAssetPath(kDbPath).string()} {}


void MyApp::setup() {
  timer.start();
  cinder::audio::SourceFileRef b_src =
      cinder::audio::load(cinder::app::loadAsset("tigertrim.mp3"));
  background_voice = cinder::audio::Voice::create(b_src);
  background_voice->start();
}

void MyApp::update() {
  auto mp = getWindow()->getMousePos();
  if (game_state == GameState::kGameOver || !background_voice->isPlaying()) {
    //populate top players
    //populate personal highs
    return;
  }

//  if (mp[0] > 5) {
//    background_voice -> start();
//  }
}

template <typename C>
void PrintText(const std::string &text, const C &color, const cinder::ivec2 &size,
               const cinder::vec2 &loc) {
  cinder::gl::color(color);
  auto box = cinder::TextBox()
      .alignment(cinder::TextBox::CENTER)
      .font(cinder::Font("Arial", 30))
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
  DrawBackground();
  if (game_state == GameState::kGameOver) {
    if (printed_game_over) {
      DrawGameOver();
      //draw game over
    }
    return;
  }
//  current_time = timer.getSeconds();
//  current_time = std::chrono::duration_cast<std::chrono::seconds>(
//      std::chrono::system_clock::now().time_since_epoch())
//      .count();
  current_time = ci::app::getElapsedSeconds();
  DrawTile();
  if ((current_time - start_time) > draw_tile_speed) {
    engine.Step();
    start_time = current_time;
  }
//  const cinder::ivec2 size = {250, 30};
//  const cinder::vec2 loc = {110, 70};
//  PrintText(player_name_, Color(0,0,1), size, loc);
}


void MyApp::mouseDown(MouseEvent event) {
  //event.isRight() || event.isLeft() || event.isMiddle()
  if (event.isLeft()) {
    //call engine funtion that will check is mouse pos is within the tile bounds
    if(!engine.MouseInTile(event.getX(), event.getY())) {
      game_state = GameState::kGameOver;
    }
  }
}

void MyApp::DrawBackground() const {
  cinder::gl::draw(my_image, getWindowBounds());
//  cinder::gl::clear(Color(0.2, 0.6, 0.7));
}

void MyApp::DrawTile() const {
  Color::white();
  const mole::Location loc = engine.GetTile().GetLocation();
  cinder::gl::drawSolidRect(Rectf(tile_size * loc.Row(),
                                  tile_size * loc.Col(),
                                  tile_size * loc.Row() + tile_size,
                                  tile_size * loc.Col() + tile_size));
}

void MyApp::DrawGameOver() {
  if (printed_game_over)
    return;
  if (top_players.empty() || personal_highs.empty())
    return;
}

}  // namespace myapp
