#include <SFML/Graphics.hpp>
#include <iostream>
#include "Timer.h"
#include "_GLOBALS.h"
#include "_COLORS.h"
#include "_HELPERS.h"
#include "Dice/Dice.h"
#include "Dice/DiceSlot.h"
#include "Form/BaseRectangle.h"
#include "Weapon/WeaponSlot.h"
#include "Weapon/WeaponHelper.h"
#include "Manager/ConfigManager.h"

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
    int weaponSlotNumber)
    : BaseRectangle(weaponSlotMenu),
      m_weaponSlotNumber(weaponSlotNumber)

{
  std::string weaponSlotKey = "WEAPONSLOT_" + std::to_string(m_weaponSlotNumber);
  m_timer = std::make_unique<Timer>(
      configManager::getRectangleX2(weaponSlotKey + "_TIMER"),
      cooldown,
      true);
  fakeDropWeaponInSlot(weaponSlotKey);
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

void WeaponSlot::fakeDropWeaponInSlot(std::string weaponSlotKey)
{
  m_bladedWeapon = std::make_unique<BladedWeapon>(
      configManager::getRectangle(weaponSlotKey + "_WEAPON"),
      GET_RANDOM_NUMBER_INT(3, 5),
      GET_RANDOM_NUMBER_INT(1, 7),
      GET_RANDOM_NUMBER_INT(1, 2),
      m_weaponSlotNumber);
}