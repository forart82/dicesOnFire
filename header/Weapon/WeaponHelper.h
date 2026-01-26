#pragma once

#include <SFML/Graphics.hpp>
#include "_HELPERS.h"
#include "Weapon/BladedWeapon.h"

inline std::unique_ptr<BladedWeapon> CREATE_BLADEDWEAPON()
{
  auto weapon = std::make_unique<BladedWeapon>(

  );

  weapon->setDamage(GET_RANDOM_NUMBER_INT(1, 10));
  weapon->setNumberOfSlots(GET_RANDOM_NUMBER_INT(1, 4));

  return weapon;
};