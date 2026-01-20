#pragma once

#include <SFML/Graphics.hpp>
#include "_BaseWeapon.h"

class Sword : public _BaseWeapon
{

private:
public:
  Sword();
  Sword(int damage, int numberOfSlots);
  ~Sword();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};