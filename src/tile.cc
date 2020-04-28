//
// Created by CSP ME on 4/23/20.
//
#include <mole/tile.h>

namespace mole {
Tile::Tile(const Location& location) : location_(location) {}

Location Tile::GetLocation() const { return location_; }

bool Tile::IsInTile(size_t mouse_x, size_t mouse_y, size_t tile_size) {
//  if () {
//    return true;
//  } else {
//    return false;
//  }
}

Tile::Tile(const Tile& tile) = default;
Tile::Tile(mole::Tile&& tile) noexcept = default;
Tile& Tile::operator=(const Tile& tile) = default;
Tile& Tile::operator=(mole::Tile&& tile) noexcept = default;
Tile::~Tile() = default;
}
