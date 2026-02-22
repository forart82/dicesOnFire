#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/BaseWeapon.h"

class BladedWeapon : public BaseWeapon
{
public:
  BladedWeapon();

  ~BladedWeapon();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};