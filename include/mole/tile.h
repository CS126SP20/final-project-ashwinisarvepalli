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
  // Represents a Tile that has a location and size attributes to draw later
  Tile(const Location&, size_t w, size_t h);

  // Rule of Five.
  Tile(const Tile&);
  Tile(Tile&&) noexcept;
  Tile& operator=(const Tile&);
  Tile& operator=(Tile&&) noexcept;
  ~Tile();

  Location GetLocation() const;
  // Checks if a mouse click is within a tile
  bool IsInTile(size_t mouse_x, size_t mouse_y);

  // Accessors
  size_t GetWidth();
  size_t GetHeight();
  bool IsClicked();
  void SetClicked(bool val);

 private:
  Location location;
  size_t width;
  size_t height;
  bool is_clicked = false;
};

}  // namespace mole

#endif  // FINALPROJECT_TILE_H
