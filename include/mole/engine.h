//
// Created by CSP ME on 4/23/20.
//

#ifndef FINALPROJECT_ENGINE_H
#define FINALPROJECT_ENGINE_H

#include <cstdlib>
#include <random>

#include "location.h"
#include "tile.h"

namespace mole {

class Engine {
 public:
  // Creates a new mole game of the given size.
  Engine(size_t width, size_t height, size_t tile_size);

  // Start the game over.
  void Reset();

  // Executes tile change pos
  void Step();

  // Checks if the mouse is in the tile step
  bool MouseInTile(size_t mouse_x, size_t mouse_y);

  size_t GetScore() const;
  Tile GetTile() const;

 private:
  Location GetRandomLocation();

 private:
  const size_t width;
  const size_t height;
  const size_t tile_size;
  Tile tile;
  size_t score;
};

}  // namespace mole

#endif  // FINALPROJECT_ENGINE_H
