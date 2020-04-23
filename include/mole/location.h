// Copyright (c) 2020 [Your Name]. All rights reserved.
#ifndef FINALPROJECT_LOCATION_H_
#define FINALPROJECT_LOCATION_H_

#include <cstddef>
#include <iostream>

namespace mole {
// Represents a location on the board.
class Location {

 public:
  Location(int row, int col);

  // Comparison operators.
  bool operator()(const Location& lhs, const Location& rhs) const;
  bool operator==(const Location& rhs) const;
  bool operator!=(const Location& rhs) const;
  bool operator<(const Location& rhs) const;
  bool operator<=(const Location& rhs) const;
  bool operator>(const Location& rhs) const;
  bool operator>=(const Location& rhs) const;

  // Accessors.
  int Row() const;
  int Col() const;

 private:
  int row_;
  int col_;
};

}  // namespace mole


#endif // FINALPROJECT_MYLIBRARY_EXAMPLE_H_
