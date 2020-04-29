#include <mole/mole_leaderboard.h>
#include <sqlite_modern_cpp.h>

namespace mole {

LeaderBoard::LeaderBoard(const std::string &db_path) : db_{db_path} {
  try {
    db_ << "CREATE TABLE if not exists leaderboard (\n"
           "  name  TEXT NOT NULL,\n"
           "  score INTEGER NOT NULL,\n"
           "  song_name TEXT NOT NULL\n"
           ");";
  } catch (const std::exception &e) {
    std::cout << "not able to create a board" << std::endl;
  }
}

void LeaderBoard::AddScoreToLeaderBoard(const Player &player,
                                        const std::string &s_name) {
  try {
    db_ << u"INSERT into leaderboard(name, score, song_name) VALUES (?,?,?);"
        << player.name << player.score << s_name;
  } catch (const std::exception &e) {
    std::cout << "not able to add to board" << std::endl;
  }
}

std::vector<Player> GetPlayers(sqlite::database_binder *rows) {
  std::vector<Player> players;
  for (auto &&row : *rows) {
    std::string name;
    size_t score;
    std::string song_name;
    row >> name >> score >> song_name;
    Player player = {name, score};
    players.push_back(player);
  }
  return players;
}

//std::vector<std::string> GetSongName() {
//
//}

std::vector<Player> LeaderBoard::RetrieveHighScores(const size_t limit,
                                                    const std::string &s_name) {
  try {
    auto rows = db_ << u"SELECT * FROM leaderboard WHERE song_name= ? ORDER BY score DESC LIMIT ?"
                    << s_name << limit;
    return GetPlayers(&rows);
  } catch (const std::exception &e) {
    std::cout << "not able to retrieve high scores" << std::endl;
    std::vector<Player> empty;
    return empty;
  }
}

std::vector<Player> LeaderBoard::RetrieveHighScores(const Player &player,
                                               const size_t limit, const std::string &s_name) {
  try {
    auto rows = db_ << u"SELECT * FROM leaderboard WHERE name= ? and song_name= ? ORDER BY "
                       u"score DESC LIMIT ?"
                    << player.name << s_name << limit;
    return GetPlayers(&rows);
  } catch (const std::exception &e) {
    std::cout << "not able to retrieve high scores of player" << std::endl;
    std::vector<Player> empty;
    return empty;
  }
}

}
