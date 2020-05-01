// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <mole/engine.h>

#include <catch2/catch.hpp>

TEST_CASE("Engine Tile and Location Basic",
          "[engine][initialize][tile][location]") {
  mole::Engine test(8, 100);
  SECTION("Original Accessors Check") {
    REQUIRE(test.GetScore() == 0);
    REQUIRE(test.GetTile().GetHeight() == 100);
    REQUIRE(test.GetTile().GetWidth() == 100);
    REQUIRE(test.GetTile().GetLocation().GetY() <= 700);
    REQUIRE(test.GetTile().GetLocation().GetY() <= 700);
    REQUIRE_FALSE(test.GetTile().IsClicked());
  }

  SECTION("Resetting Game") {
    test.Reset();
    REQUIRE(test.GetScore() == 0);
    REQUIRE_FALSE(test.GetTile().IsClicked());
  }
}

TEST_CASE("GamePlay Scoring and Stepping", "[engine][tile][location]") {
  mole::Engine test(8, 100);
  SECTION("Engine Stepping") {
    mole::Tile tile_test(test.GetTile());
    test.Step();
    REQUIRE(test.GetTile().GetLocation().GetX() !=
            tile_test.GetLocation().GetX());
    REQUIRE(test.GetTile().GetLocation().GetY() !=
            tile_test.GetLocation().GetY());
  }

  SECTION("InTile Testing") {
    int x = test.GetTile().GetLocation().GetX();
    int y = test.GetTile().GetLocation().GetY();
    REQUIRE(test.GetTile().IsInTile(x + 50, y + 50));
    REQUIRE_FALSE(test.GetTile().IsInTile(x + 200, y + 200));
    REQUIRE(test.GetTile().IsInTile(x + 80, y + 20));
  }

  SECTION("Scoring and MouseInTile Testing") {
    int x = test.GetTile().GetLocation().GetX();
    int y = test.GetTile().GetLocation().GetY();
    REQUIRE_FALSE(test.GetTile().IsClicked());
    REQUIRE(test.MouseInTile(x + 50, y + 50));
    REQUIRE(test.GetScore() == 1);
    REQUIRE(test.GetTile().IsClicked());
    REQUIRE(test.MouseInTile(x + 80, y + 20));
    REQUIRE(test.GetScore() == 1);
    REQUIRE(test.GetTile().IsClicked());
  }

  SECTION("Scoring and MouseInTile Test 2") {
    test.Step();
    int x = test.GetTile().GetLocation().GetX();
    int y = test.GetTile().GetLocation().GetY();
    REQUIRE_FALSE(test.MouseInTile(x + 200, y + 200));
    REQUIRE(test.GetScore() == 0);
    REQUIRE_FALSE(test.GetTile().IsClicked());
  }

  SECTION("Scoring and MouseInTile Test 3") {
    test.Step();
    int x = test.GetTile().GetLocation().GetX();
    int y = test.GetTile().GetLocation().GetY();
    REQUIRE(test.MouseInTile(x + 80, y + 30));
    REQUIRE(test.GetScore() == 1);
    REQUIRE(test.GetTile().IsClicked());
    test.Step();
    int x2 = test.GetTile().GetLocation().GetX();
    int y2 = test.GetTile().GetLocation().GetY();
    REQUIRE_FALSE(test.GetTile().IsClicked());
    REQUIRE(test.MouseInTile(x2 + 80, y2 + 30));
    REQUIRE(test.GetScore() == 2);
    REQUIRE(test.GetTile().IsClicked());
  }
}