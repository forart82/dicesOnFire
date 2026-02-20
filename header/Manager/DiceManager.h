#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Dice.h"
#include "Helper/RandomHelper.h"

namespace diceManager
{
  inline std::unique_ptr<Dice> CREATE_DICE(int level = 1)
  {
    auto dice = std::make_unique<Dice>();

    switch (level)
    {
    case 1:
      dice->setCooldown(randomHelper::GET_RANDOM_NUMBER_FLOAT(1, 5));
      dice->setFaces(4);
      dice->setIsOnFloor(false);
      dice->setRerolls(0);
      break;
    }

    return dice;
  }
}