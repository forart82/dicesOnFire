#include <SFML/Graphics.hpp>
#include "../header/WeaponSlot.h"
#include "../header/_BaseRectangle.h"
#include "../header/_GLOBALS.h"

WeaponSlot::WeaponSlot()
    : WeaponSlot(
          sf::Vector2f(100.f, 100.f),
          sf::Vector2f(100.f, 100.f),
          COLOR_BLUE_AQUA,
          COLOR_GRAYSCALE_DENSE_WHITE,
          true) {}

WeaponSlot::WeaponSlot(sf::Vector2f position, sf::Vector2f size, sf::Color fillColor, sf::Color outlineColor, bool isActive)
    : _BaseRectangle(position, size, fillColor, outlineColor, isActive)
{
}

WeaponSlot::~WeaponSlot() {}

void WeaponSlot::update(sf::Time &delta)
{
}

void WeaponSlot::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  _BaseRectangle::draw(target, states);
}

void WeaponSlot::makeDiceSlot(int diceBoxNumber)
{

  float paddingLeft = 5.f;
  float paddingTop = 5.f;
  float width = 758.f;
  float height = 180.f;
  float index = diceBoxNumber - 1;
  m_diceBoxs[diceBoxNumber] = std::make_unique<DiceBox>(
      sf::Vector2f(paddingLeft + width / 2, paddingTop + (height / 2) + (height * (index)) + (paddingTop * (index))),
      sf::Vector2f(width, height),
      COLORS_DICE_BOXES.at(diceBoxNumber),
      COLOR_GRAYSCALE_BLACK,
      true,
      300);
}

void WeaponSlot::makeDiceSlots()
{
  for (int i = 1; i <= m_diceBoxCounter; i++)
  {
    if (m_diceBoxs.size() < i)
    {
      makeDiceBox(i);
    }
  }
}