#pragma once

#include <SFML/Graphics.hpp>
#include "Weapon/BladedWeapon.h"

class Sword : public BladedWeapon
{

private:
public:
  Sword();
  Sword(int damage, int numberOfSlots);
  ~Sword();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};