#include <SFML/Graphics.hpp>
#include <iostream>
#include "../header/DiceMenu.h"
#include "../header/_BaseRectangle.h"
#include "../header/_GLOBALS.h"

DiceMenu::DiceMenu()
    : DiceMenu(
          sf::Vector2f(384.f, 742.5f),
          sf::Vector2f(768.f, 1485.f),
          COLOR_BLUE_CLOUDY_CLEAR_BLUE,
          COLOR_GRAYSCALE_BLACK,
          true)
{
}

DiceMenu::DiceMenu(sf::Vector2f position, sf::Vector2f size, sf::Color fillColor, sf::Color outlineColor, bool isActive)
    : _BaseRectangle(position, size, fillColor, outlineColor, isActive),
      m_diceBoxCounter(8)
{
  makeDiceBoxes();
}

DiceMenu::~DiceMenu()
{
}

void DiceMenu::makeDiceBox(int diceBoxNumber)
{

  float gap = 5.f;
  float width = 758.f;
  float height = 180.f;
  float index = diceBoxNumber - 1;
  m_diceBoxs[diceBoxNumber] = std::make_unique<DiceBox>(
      sf::Vector2f(gap + width / 2, gap + (height / 2) + (height * (index)) + (gap * (index))),
      sf::Vector2f(width, height),
      COLORS_DICE_BOXES.at(diceBoxNumber),
      COLOR_GRAYSCALE_BLACK,
      true,
      3);
}

void DiceMenu::makeDiceBoxes()
{
  for (int i = 1; i <= m_diceBoxCounter; i++)
  {
    if (m_diceBoxs.size() < i)
    {
      makeDiceBox(i);
    }
  }
}

void DiceMenu::update(sf::Time &delta)
{
  for (const auto &[key, diceBox] : m_diceBoxs)
  {
    diceBox->update(delta);
  }
}

void DiceMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  _BaseRectangle::draw(target, states);
  for (const auto &[key, diceBox] : m_diceBoxs)
  {
    target.draw(*diceBox);
  }
}