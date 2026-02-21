#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Game.h"
#include "Entity/BladedWeapon.h"
#include "Entity/BluntWeapon.h"
#include "Helper/RandomHelper.h"
#include "Manager/BaseManager.h"

class WeaponManager : public BaseManager
{
public:
  WeaponManager(Game &game);
  ~WeaponManager();

  std::unique_ptr<BladedWeapon> createBladedWeapon();
  std::unique_ptr<BluntWeapon> createBluntWeapon();
};