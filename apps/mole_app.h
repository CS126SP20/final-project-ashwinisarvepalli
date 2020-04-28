// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <cinder/audio/Voice.h>
#include <cinder/gl/Texture.h>
#include <mole/engine.h>
#include <mole/mole_leaderboard.h>
#include <mole/player.h>
#include <cinder/Timer.h>

namespace myapp {

enum class GameState {
  kPlaying,
  kGameOver,
};

class MyApp : public cinder::app::App {
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void mouseDown(cinder::app::MouseEvent) override;

 private:
  void DrawBackground() const;
  void DrawGameOver();
  void DrawTile() const;

 private:
  mole::Engine engine;
  mole::LeaderBoard leaderboard;
  cinder::audio::VoiceRef background_voice;
  const std::string player_name;
  cinder::Timer timer;
  cinder::gl::Texture2dRef my_image;
  size_t current_time;
  size_t start_time;
  const size_t tile_size;
  GameState game_state;
  bool printed_game_over;
  std::vector<mole::Player> top_players;
  std::vector<mole::Player> personal_highs;
  const double draw_tile_speed; //how many tiles to draw per second
  size_t length_of_game;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
