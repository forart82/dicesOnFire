#pragma once

#include <SFML/Graphics.hpp>
#include "_BaseRectangle.h"

class WeaponSlot : public _BaseRectangle
{

public:
  WeaponSlot();
  WeaponSlot(sf::Vector2f position, sf::Vector2f size, sf::Color fillColor, sf::Color outlineColor, bool isActive);
  ~WeaponSlot();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};