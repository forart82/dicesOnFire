#pragma once

#include <SFML/Graphics.hpp>
#include "Weapon/BaseWeapon.h"
#include "Form/BaseRectangle.h"

class BladedWeapon : public BaseWeapon
{
private:
public:
  BladedWeapon();
  BladedWeapon(
      BaseRectangle weaponMenu,
      float cooldown,
      int damage,
      int numberOfSlots,
      int weaponSlotNumber);
  ~BladedWeapon();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};