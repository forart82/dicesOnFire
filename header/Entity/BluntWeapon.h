#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Weapon.h"

class BluntWeapon : public Weapon
{
private:
public:
  BluntWeapon(
      std::unique_ptr<Rectangle> bodyBox,
      float cooldown,
      int damage,
      int numberOfSlots,
      int weaponSlotNumber,
      int left,
      int top,
      int assetsLeft,
      int assetsTop);
  ~BluntWeapon();
};
