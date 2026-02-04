#pragma once

#include <SFML/Graphics.hpp>
#include "Dice/Dice.h"
#include "_HELPERS.h"
#include "_COLORS.h"

namespace diceHelper
{
  inline std::unique_ptr<Dice> CREATE_DICE(int level = 1)
  {
    auto dice = std::make_unique<Dice>();

    switch (level)
    {
    case 1:
      dice->setCooldown(helper::GET_RANDOM_NUMBER_INT(1, 5));
      dice->setFaces(4);
      dice->setIsOnFloor(false);
      dice->setRerolls(0);
      break;
    }

    return dice;
  }
}