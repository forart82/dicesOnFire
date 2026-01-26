#include <SFML/Graphics.hpp>
#include <iostream>
#include "Timer.h"
#include "_GLOBALS.h"
#include "_COLORS.h"
#include "Dice/Dice.h"
#include "Dice/DiceSlot.h"
#include "Form/BaseRectangle.h"
#include "Weapon/WeaponSlot.h"
#include "Weapon/WeaponHelper.h"
#include "ConfigManager.h"

WeaponSlot::WeaponSlot()
    : WeaponSlot(
          BaseRectangle(),
          5,
          1)
{
}

WeaponSlot::WeaponSlot(
    BaseRectangle weaponSlotMenu,
    float cooldown,
    int orderNumber)
    : BaseRectangle(weaponSlotMenu),
      m_weaponSlotMenu(weaponSlotMenu),
      m_orderNumber(orderNumber)

{
  m_timer = std::make_unique<Timer>(
      config::getRectangleX2("WEAPONSLOT_" + std::to_string(orderNumber) + "_TIMER"),
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
  BaseRectangle::update(delta);
  m_timer->update(delta);
  m_bladedWeapon->update(delta);
}

void WeaponSlot::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  BaseRectangle::draw(target, states);
  target.draw(*m_timer);
  target.draw(*m_bladedWeapon);
}

void WeaponSlot::fakeDropWeaponInSlot()
{
  m_bladedWeapon = CREATE_BLADEDWEAPON();
}