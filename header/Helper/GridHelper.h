#pragma once

#include <cmath>
#include "Globals/Globals.h"

namespace gridHelper
{
  inline int SNAP_TO_GRID(int value)
  {
    return floor(value / globals::TILE_SIZE) * globals::TILE_SIZE;
  }
}