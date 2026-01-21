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
    : WeaponSlot(
          sf::Vector2f(0.f, 0.f),
          sf::Vector2f(600.f, 150.f),
          colors::COLOR_RED_DENSE_HOT_PINK,
          colors::COLOR_GRAYSCALE_BLACK,
          true,
          5,
          1)
{
}

WeaponSlot::WeaponSlot(
    sf::Vector2f position,
    sf::Vector2f size,
    sf::Color fillColor,
    sf::Color outlineColor,
    bool isActive,
    float cooldown,
    int orderNumber)
    : _BaseRectangle(
          position,
          size,
          fillColor,
          outlineColor,
          isActive),
      m_orderNumber(orderNumber)

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
  fakeDropWeaponInSlot();
  m_bladedWeapon->setPosition(
      sf::Vector2f(100.f, 100.f));
  m_bladedWeapon->setSize(
      sf::Vector2f(100.f, 100.f));
  m_bladedWeapon->setColors(
      colors::COLOR_BLUE_CLOUDY_DEEP_BLUE,
      colors::COLOR_GRAYSCALE_DEEP_CHARCOAL);
  m_bladedWeapon->setNumberOfSlots(2);
  m_bladedWeapon->setActive(true);
}
WeaponSlot::~WeaponSlot() {}

void WeaponSlot::update(sf::Time &delta)
{
  m_timer->update(delta);
  m_bladedWeapon->update(delta);
}

void WeaponSlot::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  _BaseRectangle::draw(target, states);
  target.draw(*m_timer);
  target.draw(*m_bladedWeapon);
}

void WeaponSlot::fakeDropWeaponInSlot()
{
  m_bladedWeapon = CREATE_BLADEDWEAPON();
}