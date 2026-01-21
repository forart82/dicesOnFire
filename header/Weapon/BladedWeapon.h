#pragma once

#include <SFML/Graphics.hpp>
#include "Weapon/_BaseWeapon.h"

class BladedWeapon : public _BaseWeapon
{
private:
public:
  BladedWeapon();
  BladedWeapon(int damage, int numberOfSlots);
  ~BladedWeapon();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};