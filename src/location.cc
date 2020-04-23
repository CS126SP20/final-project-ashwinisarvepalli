// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <mole/location.h>

namespace mole {

Location::Location(int row, int col) : row_(row), col_(col) {}

bool Location::operator==(const Location& rhs) const {
  return row_ == rhs.row_ && col_ == rhs.col_;
}

bool Location::operator()(const Location& lhs, const Location& rhs) const {
  return lhs <= rhs;
}

bool Location::operator!=(const Location& rhs) const {
  return !(*this == rhs);
}

bool Location::operator<(const Location& rhs) const {
  return row_ < rhs.row_ || (rhs.row_ >= row_ && col_ < rhs.col_);
}

bool Location::operator<=(const Location& rhs) const {
  return !(rhs < *this);
}

bool Location::operator>(const Location& rhs) const {
  return rhs < *this;
}

bool Location::operator>=(const Location& rhs) const {
  return !(*this < rhs);
}

int Location::Row() const { return row_; }

int Location::Col() const { return col_; }


}  // namespace mole
