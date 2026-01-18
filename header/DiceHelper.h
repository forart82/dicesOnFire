#pragma once

#include <SFML/Graphics.hpp>
#include "Dice.h"

class DiceHelper
{
public:
  // This is your static method
  static std::unique_ptr<Dice> create(sf::Vector2f position, sf::Color color);
};