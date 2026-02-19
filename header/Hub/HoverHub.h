#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/ToolTip.h"
#include "Entity/FloorItems.h"
#include "Entity/Inventory.h"
#include "Loader/ConfigLoader.h"

class HoverHub
{
private:
  sf::RenderWindow &m_window;
  sf::View &m_playerView;
  sf::View &m_uiView;
  ToolTip &m_toolTip;
  FloorItems &m_floorItems;
  Inventory &m_inventory;

  sf::Time m_elapsedTime;
  float m_showUpTime;

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

  template <typename T>
  void loopItemsAndCheckContains(const T &items, const sf::Vector2f &mouseWorldPosition);
  void checkContains();
  void handleElapsedTime(sf::Time &delta);
};