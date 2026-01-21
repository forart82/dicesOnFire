#include <SFML/Graphics.hpp>
#include <iostream>
#include "Dice/Dice.h"
#include "Timer.h"
#include "_GLOBALS.h"
#include "Form/_BaseRectangle.h"
#include "Weapon/WeaponSlot.h"
#include "Weapon/WeaponHelper.h"

WeaponSlot::WeaponSlot()
    : WeaponSlot({0.f, 0.f}, {600.f, 150.f}, COLOR_RED_DENSE_HOT_PINK, COLOR_GRAYSCALE_BLACK, true, 5)
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
      COLOR_TIMER_BACKGROUND,
      COLOR_GRAYSCALE_BLACK,
      sf::Vector2f(position.x, position.y + timerPaddingTop),
      sf::Vector2f(timerWidth, timerHeight),
      COLOR_TIMER_PROGRESSBAR,
      COLOR_GRAYSCALE_BLACK,
      padding,
      cooldown,
      true);

  float weaponSlotPaddingTop = 15.f;
  float weaponSlotWidth = 738.f;
  float weaponSlotHeight = 130.f;
  m_weapon = std::make_unique<WeaponSlot>(
      sf::Vector2f(position.x, position.y - weaponSlotPaddingTop),
      sf::Vector2f(weaponSlotWidth, weaponSlotHeight),
      COLOR_GRAYSCALE_DENSE_SILVER,
      COLOR_GRAYSCALE_BLACK,
      true);
}
WeaponSlot::~WeaponSlot() {}

void WeaponSlot::update(sf::Time &delta)
{
  m_timer->update(delta);
  m_weapon->update(delta);
}

void WeaponSlot::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  _BaseRectangle::draw(target, states);
  target.draw(*m_timer);
  target.draw(*m_weapon);
}

void WeaponSlot::placeDiceInSlot(int slotNumber, Dice *dice)
{
  m_dices[slotNumber] = dice;
}

void WeaponSlot::setTimerCooldown(float cooldown)
{
  m_timer->setCooldown(cooldown);
}

void WeaponSlot::fakeDropWeapon()
{
  m_weapon = CREATE_BLADEDWEAPON();
}