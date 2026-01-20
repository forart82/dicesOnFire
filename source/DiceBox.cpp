#include <SFML/Graphics.hpp>
#include <iostream>
#include "../header/DiceBox.h"
#include "../header/Dice.h"
#include "../header/Timer.h"
#include "../header/_GLOBALS.h"
#include "../header/_BaseRectangle.h"

DiceBox::DiceBox()
    : DiceBox({0.f, 0.f}, {600.f, 150.f}, COLOR_RED_DENSE_HOT_PINK, COLOR_GRAYSCALE_BLACK, true, 5)
{
}

DiceBox::DiceBox(sf::Vector2f position, sf::Vector2f size, sf::Color fillColor,
                 sf::Color outlineColor, bool isActive, float cooldown)
    : _BaseRectangle(position, size, fillColor, outlineColor, isActive)
{
  // Timer
  float paddingLeft = 5.f;
  float paddingTop = 70.f;
  float width = 748.f;
  float height = 30.f;
  std::cout << position.y << std::endl;
  m_timer = std::make_unique<Timer>(
      sf::Vector2f(position.x, position.y + paddingTop),
      sf::Vector2f(width, height),
      COLOR_VIOLET_DARK_VIOLET,
      COLOR_GRAYSCALE_BLACK,
      sf::Vector2f(position.x, position.y + paddingTop),
      sf::Vector2f(width, height),
      COLOR_GREEN_DARK_GREEN,
      COLOR_GREEN_DARK_GREEN,
      paddingLeft,
      cooldown,
      true);
}
DiceBox::~DiceBox() {}

void DiceBox::update(sf::Time &delta)
{
  m_timer->update(delta);
}

void DiceBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  _BaseRectangle::draw(target, states);
  target.draw(*m_timer);
}

void DiceBox::placeDiceInSlot(int slotNumber, Dice *dice)
{
  m_dices[slotNumber] = dice;
}

void DiceBox::setTimerCooldown(float cooldown)
{
  m_timer->setCooldown(cooldown);
}