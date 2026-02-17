#include "Hub/PickUpHub.h"

PickUpHub::PickUpHub(
    Hero &hero,
    FloorItems &floorItems,
    Inventory &inventory)
    : m_hero(hero),
      m_floorItems(floorItems),
      m_invenotry(inventory)
{
}

PickUpHub::~PickUpHub() {}

void PickUpHub::update(sf::Time &delta)
{
  pickUp();
}

void PickUpHub::pickUp()
{
  if (m_invenotry.getFreeSlotIndex() >= 0)
  {
    auto &weapons = m_floorItems.getWeapons();
    for (auto it = weapons.begin(); it != weapons.end();)
    {
      if (m_hero.insidePickUpRangeCircle((*it)->getLeftTop()) && m_invenotry.getFreeSlotIndex() >= 0)
      {
        m_invenotry.addWeapon(std::move(*it));
        it = weapons.erase(it);
      }
      else
      {
        ++it;
      }
    }

    auto &dices = m_floorItems.getDices();
    for (auto it = dices.begin(); it != dices.end();)
    {
      if (m_hero.insidePickUpRangeCircle((*it)->getLeftTop()) && m_invenotry.getFreeSlotIndex() >= 0)
      {
        m_invenotry.addDice(std::move(*it));
        it = dices.erase(it);
      }
      else
      {
        ++it;
      }
    }
  }
}