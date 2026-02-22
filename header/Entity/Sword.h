#pragma once

#include "Entity/BladedWeapon.h"

class Sword : public BladedWeapon
{

private:
public:
  Sword();
  ~Sword();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};