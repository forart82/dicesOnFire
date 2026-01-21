#pragma once

#include <SFML/Graphics.hpp>
#include "Weapon/_BaseWeapon.h"

class BladedWeapon : public _BaseWeapon
{
private:
public:
  BladedWeapon();
  BladedWeapon(
      sf::Vector2f position,
      sf::Vector2f size,
      sf::Color fillColor,
      sf::Color outlineColor,
      bool isActive,
      float cooldown,
      int damage,
      int numberOfSlots);
  ~BladedWeapon();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};