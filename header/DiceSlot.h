#pragma once

#include <SFML/Graphics.hpp>
#include "_BaseCircle.h"

class DiceSlot : public _BaseCircle
{
private:
public:
  DiceSlot();
  DiceSlot(sf::Vector2f position, float radius, sf::Color fillColor, sf::Color outlineColor, bool isActive);
  ~DiceSlot();
};