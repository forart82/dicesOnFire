#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <map>

namespace globals
{
  inline constexpr int TILE_SIZE = 64;
  inline constexpr int ASSETS_TILE_SIZE = 32;
  inline constexpr int GLOBAL_SCREEN_WIDTH = 3840;
  inline constexpr int GLOBAL_SCREEN_HEIGHT = 2176;
  // const int GLOBAL_SCREEN_WIDTH = 1920;
  // const int GLOBAL_SCREEN_HEIGHT = 1080;

  inline constexpr int PLAYER_WATCH_RADIUS = 50;

  inline constexpr int START_ZONE_WIDTH = 600;
  inline constexpr int START_ZONE_HEIGHT = 400;
  inline constexpr int SCOREBOARD_HEIGHT = 50;
  inline constexpr int TEXT_SIZE = 16;

  inline constexpr float GAP_SIZE = 0.f;
  inline constexpr float BUTTON_HEIGHT = 20.f;
  inline constexpr float BUTTON_WIDTH = 80.f;
}