#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Weapon.h"
#include "Entity/Rectangle.h"

class BladedWeapon : public Weapon
{
private:
public:
  BladedWeapon();
  BladedWeapon(
      std::unique_ptr<Rectangle> bodyBox,
      float cooldown,
      int damage,
      int numberOfSlots,
      int weaponSlotNumber);
  ~BladedWeapon();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};