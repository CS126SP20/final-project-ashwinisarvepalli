//
// Created by CSP ME on 4/27/20.
//

#ifndef FINALPROJECT_PLAYER_H
#define FINALPROJECT_PLAYER_H

#include <string>

namespace mole {
// Represents a Player that will be put into the leaderboard
struct Player {
  Player(const std::string &name, size_t score) : name(name), score(score) {}
  std::string name;
  size_t score;
};

}  // namespace mole

#endif  // FINALPROJECT_PLAYER_H
