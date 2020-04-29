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

  Tile(const Location&, size_t w, size_t h);

  // Rule of Five.
  Tile(const Tile&);
  Tile(Tile&&) noexcept;
  Tile& operator=(const Tile&);
  Tile& operator=(Tile&&) noexcept;
  ~Tile();

  Location GetLocation() const;
  bool IsInTile(size_t mouse_x, size_t mouse_y);
  bool IsInButtonTile(size_t mouse_x, size_t mouse_y);

  size_t GetWidth();
  size_t GetHeight();

 private:
  Location location;
  size_t width;
  size_t height;
};

}

#endif  // FINALPROJECT_TILE_H
