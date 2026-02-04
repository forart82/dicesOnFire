#pragma once

#include <cmath>
#include "_GLOBALS.h"
#include <random>

namespace helper
{
  inline int SNAP_TO_GRID(int value)
  {
    return floor(value / TILE_SIZE) * TILE_SIZE;
  }

  inline int GET_RANDOM_NUMBER_INT(int min, int max)
  {
    // This is a placeholder for a better random number generation strategy.
    // It's recommended to have a single std::mt19937 instance in your Game class.
    std::uniform_int_distribution<> distrib(min, max);
    static std::mt19937 gen(std::random_device{}());
    return distrib(gen);
  }

  inline float GET_RANDOM_NUMBER_FLOAT(float min, float max)
  {
    // This is a placeholder for a better random number generation strategy.
    // It's recommended to have a single std::mt19937 instance in your Game class.
    std::uniform_int_distribution<float> distrib(min, max);
    static std::mt19937 gen(std::random_device{}());
    return distrib(gen);
  }
};