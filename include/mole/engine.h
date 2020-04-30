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
  Engine(size_t length, size_t tile_size);

  // Start the game over.
  void Reset();

  // Executes tile change pos
  void Step();

  // Checks if the mouse is in the tile step and increments the score
  // accordingly
  bool MouseInTile(size_t mouse_x, size_t mouse_y);

  // Accessors
  size_t GetScore() const;
  Tile GetTile() const;

 private:
  Location GetRandomLocation();

 private:
  // will always be a square tile so only one attribute length
  const size_t length;
  const size_t tile_size;
  Tile tile;
  size_t score;
};

}  // namespace mole

#endif  // FINALPROJECT_ENGINE_H
