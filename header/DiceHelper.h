#pragma once

#include <SFML/Graphics.hpp>
#include "Dice.h"
#include "_HELPERS.h"

class DiceHelper
{
public:
  inline std::unique_ptr<Dice> CREATE_DICE(sf::Vector2f position, sf::Color color)
  {
    auto dice = std::make_unique<Dice>();

    dice->setPosition(position);
    dice->setColors(COLORS_DICE_ELEMENTS[GET_RANDOM_NUMBER_INT(1, 3)], COLOR_GRAYSCALE_BLACK);
    dice->setFaces(4);

    return dice;
  }
};