#pragma once

#include <SFML/Graphics.hpp>
#include "Helper/CollisionHelper.h"

class Circle;
class Inventory;
class FloorItems;
class Collectorable
{
private:
  Circle *m_colletocrableRangeCircle = nullptr;
  Inventory *m_collectorableInventory = nullptr;
  FloorItems *m_collectorableFloorItems = nullptr;

protected:
  float m_collectorableRangeRadius;

public:
  Collectorable() = default;
  virtual ~Collectorable() = default;

  void bind(
      Circle *colletocrableRangeCircle,
      Inventory *collectorableInventory,
      FloorItems *collectorableFloorItems);

  void updateCollectorable(const sf::Time &delta);

  bool insideColletorableRange(const sf::Vector2f &centerPosition);
};