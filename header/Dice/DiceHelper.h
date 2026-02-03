#pragma once

#include <SFML/Graphics.hpp>
#include "Dice/Dice.h"
#include "_HELPERS.h"
#include "_COLORS.h"

class DiceHelper
{
public:
  inline std::unique_ptr<Dice> CREATE_DICE(sf::Vector2f position, sf::Color color)
  {
    auto dice = std::make_unique<Dice>();

    dice->getShape().setPosition(position);
    dice->setColors(colors::COLORS_DICE_ELEMENTS[helper::GET_RANDOM_NUMBER_INT(1, 3)], colors::COLOR_GRAYSCALE_BLACK);
    dice->setFaces(4);

    return dice;
  }
};