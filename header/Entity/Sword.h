#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Game.h"
#include "Entity/BladedWeapon.h"
#include "Entity/Rectangle.h"

class Sword : public BladedWeapon
{

private:
public:
  Sword();
  ~Sword();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};