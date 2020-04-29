//
// Created by CSP ME on 4/23/20.
//

#include <cinder/Rand.h>
#include <mole/engine.h>

#include <set>

namespace mole {

Engine::Engine(size_t width, size_t height, size_t tile_size)
    : width_{width},
      height_{height},
      tile_size{tile_size},
      score{0},
      tile{GetRandomLocation()}
      {
  Reset();
}

// Retrieves a random location not for Tile.
Location Engine::GetRandomLocation() {
  Location final_location(0, 0);
  auto r = cinder::Rand::randInt(height_);
  auto c = cinder::Rand::randInt(width_);
  Location loc(r, c);
  final_location = loc;
  return final_location;
}

bool Engine::MouseInTile(size_t mouse_x, size_t mouse_y) {
  //if mouse clocked on the rectangle
  if (tile.IsInTile(mouse_x, mouse_y, tile_size)) {
    score++;
    return true;
  }
  return false;
}

void Engine::Step() {
  tile = Tile(GetRandomLocation());
}

void Engine::Reset() {
  Location location = GetRandomLocation();
  score = 0;
}

size_t Engine::GetScore() const { return score; }
Tile Engine::GetTile() const { return tile; }

}