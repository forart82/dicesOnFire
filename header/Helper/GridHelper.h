#pragma once

#include <cmath>
#include "Loader/ConfigLoader.h"

namespace gridHelper
{
  inline int TILE_SIZE = configLoader::get<int>("TILE_SIZE");

  inline int SNAP_TO_GRID(int value)
  {
    return floor(value / TILE_SIZE) * TILE_SIZE;
  }
}