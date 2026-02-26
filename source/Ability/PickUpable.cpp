#include "Ability/PickUpable.h"

void PickUpable::update(const sf::Time &delta)
{
  pickUp();
}

void PickUpable::pickUp()
{
  if (m_pickUpableIventory->getFreeSlotIndex() >= 0)
  {
    auto &weapons = m_pickUpableFloorItems->getWeapons();
    for (auto it = weapons.begin(); it != weapons.end();)
    {
      if (m_cpickUpableCollector->insidePickUpRangeCircle((*it)->getLeftTop()) && m_invenotry.getFreeSlotIndex() >= 0)
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