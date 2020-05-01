//
// Created by CSP ME on 4/23/20.
//

#include <cinder/Rand.h>
#include <mole/engine.h>

#include <cstdlib>
#include <set>

namespace mole {

Engine::Engine(size_t length, size_t tile_size)
    : length{length},
      tile_size{tile_size},
      score{0},
      tile{GetRandomLocation(), tile_size, tile_size} {
  Reset();
}

Location Engine::GetRandomLocation() {
  Location final_location(0, 0);
  srand(std::chrono::system_clock::now().time_since_epoch().count());
  auto r = cinder::Rand::randInt((length * tile_size) - tile_size);
  auto c = cinder::Rand::randInt((length * tile_size) - tile_size);
  Location loc(r, c);
  final_location = loc;
  return final_location;
}

bool Engine::MouseInTile(size_t mouse_x, size_t mouse_y) {
  if (tile.IsInTile(mouse_x, mouse_y)) {
    if (!tile.IsClicked()) {
      score++;
      tile.SetClicked(true);
    }
    return true;
  }
  return false;
}

void Engine::Step() { tile = Tile(GetRandomLocation(), tile_size, tile_size); }

void Engine::Reset() { score = 0; }

size_t Engine::GetScore() const { return score; }
Tile Engine::GetTile() const { return tile; }

}  // namespace mole