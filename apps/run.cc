// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <mole/mole_leaderboard.h>
#include <gflags/gflags.h>

#include "mole_app.h"

using cinder::app::App;
using cinder::app::RendererGl;


namespace myapp {

const int kSamples = 8;

DEFINE_uint32(size, 8, "the number of tiles in each row and column");
DEFINE_uint32(tilesize, 100, "the size of each tile");
DEFINE_string(name, "Ashie", "the name of the player");

void SetUp(App::Settings* settings) {
  const int width = static_cast<int>(FLAGS_size * FLAGS_tilesize);
  const int height = static_cast<int>(FLAGS_size * FLAGS_tilesize);

  settings->setWindowSize(width, height);
//  settings->setResizable(false);
  settings->setTitle("My CS 126 Application");
}

}  // namespace myapp


// This is a macro that runs the application.
CINDER_APP(myapp::MyApp,
           RendererGl(RendererGl::Options().msaa(myapp::kSamples)),
           myapp::SetUp)
