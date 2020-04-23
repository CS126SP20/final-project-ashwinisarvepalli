//
// Created by CSP ME on 4/23/20.
//

#ifndef FINALPROJECT_TILE_H
#define FINALPROJECT_TILE_H

#include "location.h"
namespace mole {

// Represents a Tile.
class Tile {
 public:
  explicit Tile(const Location&);

  // Rule of Five.
  Tile(const Tile&);
  Tile(Tile&&) noexcept;
  Tile& operator=(const Tile&);
  Tile& operator=(Tile&&) noexcept;
  ~Tile();

  Location GetLocation() const;

 private:
  Location location_;
};

}

#endif  // FINALPROJECT_TILE_H
