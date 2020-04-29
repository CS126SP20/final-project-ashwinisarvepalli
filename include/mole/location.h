// Copyright (c) 2020 [Your Name]. All rights reserved.
#ifndef FINALPROJECT_LOCATION_H_
#define FINALPROJECT_LOCATION_H_

#include <cstddef>
#include <iostream>

namespace mole {
// Represents a location on the board.
class Location {

 public:
  Location(size_t x, size_t y);

  // Accessors.
  int GetX() const;
  int GetY() const;

 private:
  int x;
  int y;
};

}  // namespace mole


#endif // FINALPROJECT_MYLIBRARY_EXAMPLE_H_
