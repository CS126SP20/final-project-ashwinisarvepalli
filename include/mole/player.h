//
// Created by CSP ME on 4/27/20.
//

#ifndef FINALPROJECT_PLAYER_H
#define FINALPROJECT_PLAYER_H

#include <string>

namespace mole {

struct Player {
  Player(const std::string &name, size_t score)
      : name(name), score(score) {}
  std::string name;
  size_t score;
};

}

#endif  // FINALPROJECT_PLAYER_H
