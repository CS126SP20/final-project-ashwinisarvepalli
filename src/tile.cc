//
// Created by CSP ME on 4/23/20.
//
#include <mole/tile.h>

namespace mole {

Tile::Tile(const Location& loc, size_t w, size_t h)
    : location{loc}, width{w}, height{h} {}

Location Tile::GetLocation() const { return location; }

bool Tile::IsInTile(size_t mouse_x, size_t mouse_y) {
  return ((mouse_x > (location.GetX() * width)) &&
          (mouse_x < (location.GetX() * width + width))) &&
         ((mouse_y > (location.GetY() * height)) &&
          (mouse_y < (location.GetY() * height + height)));
}

size_t Tile::GetWidth() { return width; }
size_t Tile::GetHeight() { return height; }

bool Tile::IsInButtonTile(size_t mouse_x, size_t mouse_y) {
  return ((mouse_x > location.GetX()) &&
          (mouse_x < (location.GetX() + width))) &&
         ((mouse_y > location.GetY()) &&
          (mouse_y < (location.GetY() + height)));
}

Tile::Tile(const Tile& tile) = default;
Tile::Tile(mole::Tile&& tile) noexcept = default;
Tile& Tile::operator=(const Tile& tile) = default;
Tile& Tile::operator=(mole::Tile&& tile) noexcept = default;
Tile::~Tile() = default;
}  // namespace mole
