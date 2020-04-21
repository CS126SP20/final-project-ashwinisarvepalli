#include <mole/mole_leaderboard.h>
#include <sqlite_modern_cpp.h>

namespace mole {

LeaderBoard::LeaderBoard(const std::string &db_path) : db_{db_path} {
  try {
    db_ << "CREATE TABLE if not exists leaderboard (\n"
           "  name  TEXT NOT NULL,\n"
           "  score INTEGER NOT NULL,\n"
           "  time DOUBLE NOT NULL\n"
           ");";
  } catch (const std::exception &e) {
    std::cout << "not able to create a board" << std::endl;
  }
}

}
