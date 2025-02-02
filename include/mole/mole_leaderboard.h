// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_LEADERBOARD_H_
#define FINALPROJECT_LEADERBOARD_H_

#include <sqlite_modern_cpp.h>

#include <string>
#include <vector>

#include "player.h"

namespace mole {

class LeaderBoard {
 public:
  // Creates a new leaderboard table if it doesn't already exist.
  explicit LeaderBoard(const std::string& db_path);

  // Adds a player to the leaderboard.
  void AddScoreToLeaderBoard(const Player&, const std::string& s_name);

  // Returns a list of the players with the highest scores, in decreasing order
  // of the given song name. The size of the list should be no greater than
  // `limit`.
  std::vector<Player> RetrieveHighScores(const size_t limit,
                                         const std::string& s_name);

  // Returns a list of the players with the highest scores of the given song
  // name, in decreasing order, that have the same `name` as the input player
  // name. The size of the list should be no greater than `limit`.
  std::vector<Player> RetrieveHighScores(const Player&, const size_t limit,
                                         const std::string& s_name);

 private:
  sqlite::database db_;
};

}  // namespace mole

#endif  // SNAKE_LEADERBOARD_H_
