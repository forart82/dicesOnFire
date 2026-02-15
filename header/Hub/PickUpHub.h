#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Hero.h"
#include "Entity/FloorItems.h"
#include "Entity/Inventory.h"
#include "Helper/CollisionHelper.h"

class PickUpHub
{
private:
  Hero &m_hero;
  FloorItems &m_floorItems;
  Inventory &m_invenotry;

public:
  PickUpHub(
      Hero &hero,
      FloorItems &floorItems,
      Inventory &Inventory);

  ~PickUpHub();

  void update(sf::Time &delta);
  void pickUp();
};