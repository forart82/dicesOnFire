#pragma once

#include <SFML/Graphics.hpp>
#include "Ability/Collectable.h"
#include "Entity/FloorItems.h"
#include "Entity/Inventory.h"

class PickUpable
{
private:
  Collectable *m_cpickUpableCollector = nullptr;
  FloorItems *m_pickUpableFloorItems = nullptr;
  Inventory *m_pickUpableIventory = nullptr;

public:
  PickUpable() = default;
  virtual ~PickUpable() = default;

  void update(const sf::Time &delta);
  void pickUp();
};