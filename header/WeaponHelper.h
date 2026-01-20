#pragma once

#include <SFML/Graphics.hpp>
#include "_HELPERS.h"
#include "Sword.h"

inline std::unique_ptr<_BaseWeapon> CREATE_WEAPON()
{
  auto weapon = std::make_unique<Sword>();

  weapon->setDamage(GET_RANDOM_NUMBER_INT(1, 10));
  weapon->setNumberOfSlots(GET_RANDOM_NUMBER_INT(1, 4));

  return weapon;
};