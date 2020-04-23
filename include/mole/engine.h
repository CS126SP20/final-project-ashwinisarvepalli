//
// Created by CSP ME on 4/23/20.
//

#ifndef FINALPROJECT_ENGINE_H
#define FINALPROJECT_ENGINE_H

#include "location.h"
#include "tile.h"
namespace mole {
class Engine {
 public:
  // Creates a new tile game of the given size.
  Engine(size_t width, size_t height);

  // Creates a new tile game of the given size, seeded.
  Engine(size_t width, size_t height, unsigned seed);

  // Start the game over.
  void Reset();

  size_t GetScore() const;
  Tile GetFood() const;

 private:
  Location GetRandomLocation();

 private:
  const size_t width_;
  const size_t height_;
  Tile tile;
};

}

#endif  // FINALPROJECT_ENGINE_H
