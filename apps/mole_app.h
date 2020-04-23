// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <cinder/gl/Texture.h>
#include <mole/mole_leaderboard.h>

namespace myapp {

class MyApp : public cinder::app::App {
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;

 private:
  void DrawBackground() const;
  void DrawTiles() const;

 private:
  mole::LeaderBoard leaderboard_;
  const std::string player_name_;
  cinder::gl::Texture2dRef myImage;


};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
