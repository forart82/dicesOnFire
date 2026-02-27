#include "Ability/Collectorable.h"

void Collectorable::bind(
    Circle *colletocrableRangeCircle,
    Inventory *collectorableInventory,
    FloorItems *collectorableFloorItems)
{
  m_colletocrableRangeCircle = colletocrableRangeCircle;
  m_collectorableInventory = collectorableInventory;
  m_collectorableFloorItems = collectorableFloorItems;
}

void Collectorable::updateCollectorable(const sf::Time &delta)
{

  auto &weapons = m_collectorableFloorItems->getWeapons();
  for (auto it = weapons.begin(); it != weapons.end();)
  {
    // 1. Cleaner Check: referencing the Item's new capability
    // We also check inventory space here because that belongs to the "Manager" logic
    if ((*it)->canBePickedUp(this))
    {
      // 2. The Move: Transfer ownership from Floor -> Inventory
      m_collectorableInventory->addWeapon(std::move(*it));

      // 3. The Delete: Remove the empty shell from the floor list
      // erase() returns the iterator to the NEXT item, so we don't need ++it
      it = weapons.erase(it);
    }
    else
    {
      // Only increment if we didn't delete anything
      ++it;
    }
  }

  auto &dices = m_collectorableFloorItems->getDices();
  for (auto it = dices.begin(); it != dices.end();)
  {
    // 1. Cleaner Check: referencing the Item's new capability
    // We also check inventory space here because that belongs to the "Manager" logic
    if ((*it)->canBePickedUp(this))
    {
      // 2. The Move: Transfer ownership from Floor -> Inventory
      m_collectorableInventory->addDice(std::move(*it));

      // 3. The Delete: Remove the empty shell from the floor list
      // erase() returns the iterator to the NEXT item, so we don't need ++it
      it = weapons.erase(it);
    }
    else
    {
      // Only increment if we didn't delete anything
      ++it;
    }
  }
}

bool Collectorable::insideColletorableRange(const sf::Vector2f &centerPosition)
{
  return collisionHelper::insideRadar(centerPosition, *m_colletocrableRangeCircle);
}