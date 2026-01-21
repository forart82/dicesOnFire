#include <SFML/Graphics.hpp>
#include <iostream>
#include "Weapon/WeaponSlotsMenu.h"
#include "Form/_BaseRectangle.h"
#include "_GLOBALS.h"

WeaponSlotsMenu::WeaponSlotsMenu()
    : WeaponSlotsMenu(
          sf::Vector2f(384.f, 742.5f),
          sf::Vector2f(768.f, 1485.f),
          COLOR_BLUE_CLOUDY_CLEAR_BLUE,
          COLOR_GRAYSCALE_BLACK,
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

  float paddingLeft = 5.f;
  float paddingTop = 5.f;
  float width = 758.f;
  float height = 180.f;
  float index = weaponSlotNumber - 1;
  m_weaponSlots[weaponSlotNumber] = std::make_unique<WeaponSlot>(
      sf::Vector2f(paddingLeft + width / 2, paddingTop + (height / 2) + (height * (index)) + (paddingTop * (index))),
      sf::Vector2f(width, height),
      COLORS_DICE_BOXES.at(weaponSlotNumber),
      COLOR_GRAYSCALE_BLACK,
      true,
      300);
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