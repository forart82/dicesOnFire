#include <SFML/Graphics.hpp>
#include "../header/Dice.h"
#include "../header/DiceHelper.h"
#include "../header/_GLOBALS.h"
#include "../header/_HELPERS.h"

std::unique_ptr<Dice> DiceHelper::create(sf::Vector2f position, sf::Color color)
{
  auto dice = std::make_unique<Dice>();

  dice->setPosition(position);
  dice->setColors(COLORS_DICE_ELEMENTS[GET_RANDOM_NUMBER_INT(1, 3)], COLOR_GRAYSCALE_BLACK);
  dice->setFaces(4);

  return dice;
}