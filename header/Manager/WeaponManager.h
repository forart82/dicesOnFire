#pragma once

#include <SFML/Graphics.hpp>
#include "Helper/RandomHelper.h"
#include "Entity/BladedWeapon.h"
#include "Entity/BluntWeapon.h"

namespace weaponManager
{
  inline std::unique_ptr<BladedWeapon> CREATE_BLADEDWEAPON()
  {
    auto weapon = std::make_unique<BladedWeapon>(

    );

    weapon->setDamage(randomHelper::GET_RANDOM_NUMBER_INT(1, 10));
    weapon->setNumberOfSlots(randomHelper::GET_RANDOM_NUMBER_INT(1, 4));

    return std::move(weapon);
  }

  inline std::unique_ptr<BluntWeapon> CREATE_BLUNTWEAPON()
  {

    float cooldown = randomHelper::GET_RANDOM_NUMBER_FLOAT(1, 3);
    int damage = randomHelper::GET_RANDOM_NUMBER_INT(1, 10);
    int numberOfSlots = randomHelper::GET_RANDOM_NUMBER_INT(1, 4);
    int assetsLeft = 1376;
    int assetsTop = 1504;

    auto weapon = std::make_unique<BluntWeapon>(
        std::make_unique<Rectangle>(),
        cooldown,
        damage,
        numberOfSlots,
        0,
        0,
        0,
        assetsLeft,
        assetsTop);

    return std::move(weapon);
  }
};