#pragma once

#include <cmath>
#include "Loader/ConfigLoader.h"

namespace gridHelper
{
  inline int SNAP_TO_GRID(int value)
  {
    return floor(value / configLoader::getInteger("TILE_SIZE")) * configLoader::getInteger("TILE_SIZE");
  }
}