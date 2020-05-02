// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/Timer.h>
#include <cinder/app/App.h>
#include <cinder/audio/Voice.h>
#include <cinder/gl/Texture.h>
#include <mole/engine.h>
#include <mole/mole_leaderboard.h>
#include <mole/player.h>

namespace myapp {

enum class GameState {
  kHome,
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
  void DrawHome();
  void DrawTile() const;
  void DrawScore();
  void ResetGame();

 private:
  mole::Tile easy{mole::Location{200, 250}, 400, 100};
  mole::Tile medium{mole::Location{200, 400}, 400, 100};
  mole::Tile hard{mole::Location{200, 550}, 400, 100};
  mole::Engine engine;
  mole::LeaderBoard leaderboard;
  cinder::audio::VoiceRef background_voice;
  cinder::audio::SourceFileRef e_src;
  cinder::audio::SourceFileRef m_src;
  cinder::audio::SourceFileRef h_src;
  const std::string player_name;
  cinder::gl::Texture2dRef bg_image;
  cinder::gl::TextureRef tile_image;
  size_t current_time;
  size_t start_time;
  GameState game_state;
  bool printed_game_over;
  bool printed_home;
  std::vector<mole::Player> top_players;
  std::vector<mole::Player> personal_highs;
  double draw_tile_speed;
  std::string song_name;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
