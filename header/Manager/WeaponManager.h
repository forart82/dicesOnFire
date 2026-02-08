#pragma once

#include <SFML/Graphics.hpp>
#include "Helper/RandomHelper.h"
#include "Entity/BladedWeapon.h"

inline std::unique_ptr<BladedWeapon> CREATE_BLADEDWEAPON()
{
  auto weapon = std::make_unique<BladedWeapon>(

  );

  weapon->setDamage(randomHelper::GET_RANDOM_NUMBER_INT(1, 10));
  weapon->setNumberOfSlots(randomHelper::GET_RANDOM_NUMBER_INT(1, 4));

  return weapon;
};