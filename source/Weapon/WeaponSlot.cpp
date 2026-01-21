#include <SFML/Graphics.hpp>
#include <iostream>
#include "Timer.h"
#include "_GLOBALS.h"
#include "_COLORS.h"
#include "Dice/Dice.h"
#include "Dice/DiceSlot.h"
#include "Form/_BaseRectangle.h"
#include "Weapon/WeaponSlot.h"
#include "Weapon/WeaponHelper.h"

WeaponSlot::WeaponSlot()
    : WeaponSlot({0.f, 0.f}, {600.f, 150.f}, colors::COLOR_RED_DENSE_HOT_PINK, colors::COLOR_GRAYSCALE_BLACK, true, 5)
{
}

WeaponSlot::WeaponSlot(sf::Vector2f position, sf::Vector2f size, sf::Color fillColor,
                       sf::Color outlineColor, bool isActive, float cooldown)
    : _BaseRectangle(position, size, fillColor, outlineColor, isActive)
{
  float padding = 5.f;
  // Timer
  float timerPaddingTop = 70.f;
  float timerWidth = 748.f;
  float timerHeight = 30.f;
  std::cout << position.y << std::endl;
  m_timer = std::make_unique<Timer>(
      sf::Vector2f(position.x, position.y + timerPaddingTop),
      sf::Vector2f(timerWidth, timerHeight),
      colors::COLOR_TIMER_BACKGROUND,
      colors::COLOR_GRAYSCALE_BLACK,
      sf::Vector2f(position.x, position.y + timerPaddingTop),
      sf::Vector2f(timerWidth, timerHeight),
      colors::COLOR_TIMER_PROGRESSBAR,
      colors::COLOR_GRAYSCALE_BLACK,
      padding,
      cooldown,
      true);
}
WeaponSlot::~WeaponSlot() {}

void WeaponSlot::update(sf::Time &delta)
{
  m_timer->update(delta);
}

void WeaponSlot::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  _BaseRectangle::draw(target, states);
  target.draw(*m_timer);
}

void WeaponSlot::fakeDropWeapon()
{
  m_bladedWeapon = CREATE_BLADEDWEAPON();
}