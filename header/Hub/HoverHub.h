#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/ToolTip.h"
#include "Entity/FloorItems.h"
#include "Entity/Inventory.h"

class HoverHub
{
private:
  sf::RenderWindow &m_window;
  sf::View &m_playerView;
  sf::View &m_uiView;
  ToolTip &m_toolTip;
  FloorItems &m_floorItems;
  Inventory &m_inventory;

public:
  HoverHub(
      sf::RenderWindow &window,
      sf::View &playerView,
      sf::View &uiView,
      ToolTip &toolTip,
      FloorItems &floorItems,
      Inventory &inventory);

  ~HoverHub();

  void update(sf::Time &delta);
  void checkContains();
};