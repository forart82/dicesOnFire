#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Game.h"
#include "Entity/Dice.h"
#include "Helper/RandomHelper.h"
#include "Loader/RandomNameLoader.h"
#include "Manager/BaseManager.h"

class DiceManager : public BaseManager
{

public:
  DiceManager();
  ~DiceManager();

  std::unique_ptr<Dice> createDice(int level = 1);
};