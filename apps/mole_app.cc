// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "mole_app.h"

#include <cinder/app/App.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include <gflags/gflags.h>

#include <cinder/Font.h>
#include <cinder/Text.h>
#include <cinder/Vector.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <string>

namespace myapp {
using cinder::Color;
const char kDbPath[] = "mole.db";

using cinder::app::KeyEvent;

DECLARE_string(name);

MyApp::MyApp()
  :  player_name_{FLAGS_name},
     leaderboard_{cinder::app::getAssetPath(kDbPath).string()} {}


void MyApp::setup() {

}

void MyApp::update() { }



void MyApp::draw() {
  DrawBackground();
}

void MyApp::keyDown(KeyEvent event) { }

void MyApp::DrawBackground() const {
  cinder::gl::clear(Color(0.2, 0.6, 0.7));
}

}  // namespace myapp
