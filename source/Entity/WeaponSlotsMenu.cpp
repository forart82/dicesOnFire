#include "Entity/WeaponSlotsMenu.h"

WeaponSlotsMenu::WeaponSlotsMenu()
    : WeaponSlotsMenu(
          std::make_unique<Rectangle>())
{
}

WeaponSlotsMenu::WeaponSlotsMenu(
    std::unique_ptr<Rectangle> bodyBox)
    : m_bodyBox(std::move(bodyBox)),
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
      std::make_unique<Rectangle>(configLoader::get<Rectangle>(weaponSlotConfig)),
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
  m_bodyBox->update(delta);
  for (const auto &[key, weaponSlot] : m_weaponSlots)
  {
    weaponSlot->update(delta);
  }
}

void WeaponSlotsMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(*m_bodyBox);
  for (const auto &[key, weaponSlot] : m_weaponSlots)
  {
    target.draw(*weaponSlot);
  }
}