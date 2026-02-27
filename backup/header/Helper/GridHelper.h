#pragma once

#include <cmath>

namespace gridHelper
{
  inline int SNAP_TO_GRID(int value, int tileSize)
  {
    return floor(value / tileSize) * tileSize;
  }
}