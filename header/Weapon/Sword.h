#pragma once

#include <SFML/Graphics.hpp>
#include "Weapon/BladedWeapon.h"
#include "Form/BaseRectangle.h"

class Sword : public BladedWeapon
{

private:
public:
  Sword();
  Sword(
      BaseRectangle swordMenu,
      float cooldown,
      int damage,
      int numberOfSlots);
  ~Sword();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};