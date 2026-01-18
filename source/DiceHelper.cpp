#include <SFML/Graphics.hpp>
#include "Dice.h"
#include "DiceHelper.h"

std::unique_ptr<Dice> DiceHelper::create(sf::Vector2f position, sf::Color color)
{
  // Create the unique_ptr
  auto dice = std::make_unique<Dice>();

  // Centralized setup logic
  dice->setPosition(position);
  dice->setColor(color);

  // You can even set up the onTimeout here if needed
  // dice->onTimeout = ...;

  return dice; // Return by value (it automatically moves)
}