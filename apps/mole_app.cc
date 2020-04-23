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

MyApp::MyApp()
  :  player_name_{FLAGS_name},
     myImage{gl::Texture2d::create(loadImage( loadAsset( "cosmicbg.jpg")))},
     leaderboard_{cinder::app::getAssetPath(kDbPath).string()} {}


void MyApp::setup() {

}

void MyApp::update() { }

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
//  const cinder::ivec2 size = {250, 30};
//  const cinder::vec2 loc = {110, 70};
//  PrintText(player_name_, Color(0,0,1), size, loc);
}

void MyApp::keyDown(KeyEvent event) { }

void MyApp::DrawBackground() const {
  cinder::gl::draw(myImage, getWindowBounds());
//  cinder::gl::clear(Color(0.2, 0.6, 0.7));
}
void MyApp::DrawTiles() const {

}

}  // namespace myapp
