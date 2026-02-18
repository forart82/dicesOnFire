#include "Hub/HoverHub.h"

HoverHub::HoverHub(
    sf::RenderWindow &window,
    sf::View &playerView,
    sf::View &uiView,
    ToolTip &toolTip,
    FloorItems &floorItems,
    Inventory &inventory)
    : m_window(window),
      m_playerView(playerView),
      m_uiView(uiView),
      m_toolTip(toolTip),
      m_floorItems(floorItems),
      m_inventory(inventory)
{
}

HoverHub::~HoverHub()
{
}

void HoverHub::update(sf::Time &delta)
{
  checkContains();
}

void HoverHub::checkContains()
{
  sf::Vector2i mousPos = sf::Mouse::getPosition(m_window);
  sf::Vector2f mouseWorldPos = m_window.mapPixelToCoords(mousPos, m_playerView);
  for (auto &dice : m_floorItems.getDices())
  {
    sf::FloatRect bounds = dice->getGlobalBounds();
    std::cout << bounds.position.x << " " << bounds.position.y << " " << mouseWorldPos.x << " " << mouseWorldPos.y << std::endl;
    if (dice->getGlobalBounds().contains(mouseWorldPos))
    {
      m_toolTip.setIsActive(true);
    }
  }
}
