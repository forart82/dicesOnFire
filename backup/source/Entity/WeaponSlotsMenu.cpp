#include "Entity/WeaponSlotsMenu.h"

WeaponSlotsMenu::WeaponSlotsMenu()
{
  makeWeaponSlotes();
}

WeaponSlotsMenu::~WeaponSlotsMenu()
{
}

void WeaponSlotsMenu::update(sf::Time &delta)
{
  m_body->update(delta);
  for (const auto &[key, weaponSlot] : m_weaponSlots)
  {
    weaponSlot->update(delta);
  }
}

void WeaponSlotsMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(*m_body);
  for (const auto &[key, weaponSlot] : m_weaponSlots)
  {
    target.draw(*weaponSlot);
  }
}

void WeaponSlotsMenu::makeWeaponSlot(int weaponSlotNumber)
{
  float index = weaponSlotNumber - 1;
  std::string weaponSlotConfig = "WEAPONSLOT_" + std::to_string(weaponSlotNumber);
  m_weaponSlots[weaponSlotNumber] = m_game->getWeaponSlotManager().create<WeaponSlot>();
  m_weaponSlots[weaponSlotNumber]->setBody(
      std::make_unique<Rectangle>(
          m_game->getConfigLoader().get<Rectangle>(weaponSlotConfig)));
  m_weaponSlots[weaponSlotNumber]->setCooldown(3);
  m_weaponSlots[weaponSlotNumber]->setWeaponSlotNumber(weaponSlotNumber);
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

void WeaponSlotsMenu::setBody(std::unique_ptr<Rectangle> body)
{
  m_body = std::move(body);
}