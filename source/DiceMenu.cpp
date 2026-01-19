#include <SFML/Graphics.hpp>
#include <iostream>
#include "../header/DiceMenu.h"
#include "../header/_BaseRectangle.h"
#include "../header/_GLOBALS.h"

DiceMenu::DiceMenu()
    : _BaseRectangle(
          {(GLOBAL_SCREEN_WIDTH * 0.2f) / 2.f, (GLOBAL_SCREEN_HEIGHT * 0.7f) / 2.f},
          {GLOBAL_SCREEN_WIDTH * 0.2f, GLOBAL_SCREEN_HEIGHT * 0.7f},
          COLOR_BLUE_CLOUDY_CLEAR_BLUE,
          COLOR_GRAYSCALE_BLACK,
          true)
{
}

DiceMenu::DiceMenu(sf::Vector2f position, sf::Vector2f size, sf::Color fillColor, sf::Color outlineColor, bool isActive)
    : _BaseRectangle(position, size, fillColor, outlineColor, isActive),
      m_diceBoxCounter(1)
{
  makeDiceBoxes();
}

DiceMenu::~DiceMenu()
{
}

void DiceMenu::makeDiceBox(int diceoxNumber)
{
  m_diceBoxs[m_diceBoxCounter] = std::make_unique<DiceBox>(
      sf::Vector2f(m_position.x + 50.f, m_position.y + 50.f),
      sf::Vector2f((m_size.x - 100.f) / 8, m_size.y - 50.f),
      COLOR_BLUE_CLOUDY_DEEP_BLUE,
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
    std::cout << "is create and drawing" << std::endl;
    target.draw(*diceBox);
  }
}