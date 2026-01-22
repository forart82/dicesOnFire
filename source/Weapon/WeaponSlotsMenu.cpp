#include <SFML/Graphics.hpp>
#include <iostream>
#include "Weapon/WeaponSlotsMenu.h"
#include "Form/_BaseRectangle.h"
#include "_COLORS.h"
#include "ConfigManager.h"

WeaponSlotsMenu::WeaponSlotsMenu()
    : WeaponSlotsMenu(
          sf::Vector2f(config::getKey("WEAPONSLOTSMENU_POSITION")),
          sf::Vector2f(config::getKey("WEAPONSLOTSMENU_SIZE")),
          colors::COLOR_BLUE_CLOUDY_AQUA,
          colors::COLOR_GRAYSCALE_BLACK,
          true)
{
}

WeaponSlotsMenu::WeaponSlotsMenu(sf::Vector2f position, sf::Vector2f size, sf::Color fillColor, sf::Color outlineColor, bool isActive)
    : _BaseRectangle(position, size, fillColor, outlineColor, isActive),
      m_weaponSlotCounter(8)
{
  makeWeaponSlotes();
}

WeaponSlotsMenu::~WeaponSlotsMenu()
{
}

void WeaponSlotsMenu::makeWeaponSlot(int weaponSlotNumber)
{
  float index = weaponSlotNumber - 1;
  std::string positionString = "WEAPONSLOT_" + std::to_string(weaponSlotNumber) + "_POSITION";
  std::string sizeString = "WEAPONSLOT_" + std::to_string(weaponSlotNumber) + "_SIZE";
  m_weaponSlots[weaponSlotNumber] = std::make_unique<WeaponSlot>(
      sf::Vector2f(config::getKey(positionString)),
      sf::Vector2f(config::getKey(sizeString)),
      colors::COLORS_DICE_BOXES.at(weaponSlotNumber),
      colors::COLOR_GRAYSCALE_BLACK,
      true,
      300,
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
  for (const auto &[key, weaponSlot] : m_weaponSlots)
  {
    weaponSlot->update(delta);
  }
}

void WeaponSlotsMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  _BaseRectangle::draw(target, states);
  for (const auto &[key, weaponSlot] : m_weaponSlots)
  {
    target.draw(*weaponSlot);
  }
}