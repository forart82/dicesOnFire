#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/BladedWeapon.h"
#include "Entity/Rectangle.h"

class Sword : public BladedWeapon
{

private:
public:
  Sword();
  Sword(
      std::unique_ptr<Rectangle> bodyBox,
      float cooldown,
      int damage,
      int numberOfSlots,
      int weaponSlotNumber);
  ~Sword();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};