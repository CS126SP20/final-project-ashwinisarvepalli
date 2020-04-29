// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <mole/location.h>

namespace mole {

Location::Location(size_t x, size_t y) : x(x), y(y) {}

int Location::GetX() const { return x; }

int Location::GetY() const { return y; }

}  // namespace mole
