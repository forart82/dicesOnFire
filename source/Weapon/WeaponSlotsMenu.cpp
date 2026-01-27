#include <SFML/Graphics.hpp>
#include <iostream>
#include "Weapon/WeaponSlotsMenu.h"
#include "Form/BaseRectangle.h"
#include "_COLORS.h"
#include "ConfigManager.h"

WeaponSlotsMenu::WeaponSlotsMenu()
    : WeaponSlotsMenu(config::getRectangle("WEAPONSLOTSMENU"))
{
}

WeaponSlotsMenu::WeaponSlotsMenu(
    BaseRectangle weaponSlotsMenuMenu)
    : BaseRectangle(weaponSlotsMenuMenu),
      m_weaponSlotCounter(1)
{
  makeWeaponSlotes();
}

WeaponSlotsMenu::~WeaponSlotsMenu()
{
}

void WeaponSlotsMenu::makeWeaponSlot(int weaponSlotNumber)
{
  float index = weaponSlotNumber - 1;
  std::string weaponSlotConfig = "WEAPONSLOT_" + std::to_string(weaponSlotNumber);
  m_weaponSlots[weaponSlotNumber] = std::make_unique<WeaponSlot>(
      config::getRectangle(weaponSlotConfig),
      5,
      weaponSlotNumber);
}

void WeaponSlotsMenu::makeWeaponSlotes()
{
  for (int i = 1; i <= m_weaponSlotCounter; i++)
  {
    if (m_weaponSlots.size() < i)
    {
      makeWeaponSlot(i);
    }
  }
}

void WeaponSlotsMenu::update(sf::Time &delta)
{
  BaseRectangle::update(delta);
  for (const auto &[key, weaponSlot] : m_weaponSlots)
  {
    weaponSlot->update(delta);
  }
}

void WeaponSlotsMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  BaseRectangle::draw(target, states);
  for (const auto &[key, weaponSlot] : m_weaponSlots)
  {
    target.draw(*weaponSlot);
  }
}