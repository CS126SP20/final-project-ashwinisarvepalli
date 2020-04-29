//
// Created by CSP ME on 4/23/20.
//

#include <cinder/Rand.h>
#include <mole/engine.h>

#include <set>

namespace mole {

Engine::Engine(size_t width, size_t height, size_t tile_size)
    : width{width},
      height{height},
      tile_size{tile_size},
      score{0},
      tile{GetRandomLocation(), tile_size, tile_size} {
  Reset();
}

Location Engine::GetRandomLocation() {
  Location final_location(0, 0);
  auto r = cinder::Rand::randInt(height);
  auto c = cinder::Rand::randInt(width);
  Location loc(r, c);
  final_location = loc;
  return final_location;
}

bool Engine::MouseInTile(size_t mouse_x, size_t mouse_y) {
  if (tile.IsInTile(mouse_x, mouse_y)) {
    score++;
    return true;
  }
  return false;
}

void Engine::Step() { tile = Tile(GetRandomLocation(), tile_size, tile_size); }

void Engine::Reset() {
  Location location = GetRandomLocation();
  score = 0;
}

size_t Engine::GetScore() const { return score; }
Tile Engine::GetTile() const { return tile; }

}  // namespace mole