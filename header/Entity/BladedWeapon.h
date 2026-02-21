#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/BaseWeapon.h"
#include "Entity/Rectangle.h"

class BladedWeapon : public BaseWeapon
{
public:
  BladedWeapon(Game &game);

  ~BladedWeapon();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};