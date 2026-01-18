#include <SFML/Graphics.hpp>
#include <iostream>
#include "../header/DiceBox.h"
#include "../header/Dice.h"
#include "../header/Timer.h"
#include "../header/_GLOBALS.h"

DiceBox::DiceBox()
    : DiceBox({0.f, 0.f}, {600.f, 150.f}, COLOR_RED_DENSE_HOT_PINK, 5)
{
}

DiceBox::DiceBox(sf::Vector2f position, sf::Vector2f size, sf::Color color, float cooldown)
    : m_position(position), m_size(size), m_backgroundColor(color)
{
  // Box
  m_boxShape.setFillColor(m_backgroundColor);
  m_boxShape.setSize(m_size);
  m_boxShape.setPosition(m_position);

  // Timer
  m_timer = std::make_unique<Timer>(5, true, sf::Vector2f(position.x + 10, position.y + 110), sf::Vector2f(580, 30), 5);
}
DiceBox::~DiceBox() {}

void DiceBox::update(sf::Time &delta)
{
  m_timer->update(delta);
}

void DiceBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(m_boxShape);
  target.draw(*m_timer);
}

void DiceBox::addDice(int slotNumber, Dice *dice)
{
  m_dices[slotNumber] = dice;
}

void DiceBox::setTimerCooldown(float cooldown)
{
  m_timer->setCooldown(cooldown);
}