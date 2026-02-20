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
      m_inventory(inventory),
      m_showUpTime(configLoader::get<float>("HOVER_SHOW_UP_TIME"))
{
}

HoverHub::~HoverHub()
{
}

void HoverHub::update(sf::Time &delta)
{
  checkContains();
  handleElapsedTime(delta);
}

template <typename T>
void HoverHub::loopItemsAndCheckContains(const T &items, const sf::Vector2f &mouseWorldPosition)
{
  for (auto &item : items)
  {
    sf::FloatRect bounds = item->getGlobalBounds();
    if (item->getGlobalBounds().contains(mouseWorldPosition))
    {
      m_toolTip.setTitle(item->getName());
      m_toolTip.setStats(item->getStats());
      m_toolTip.setIsActive(true);
      m_elapsedTime = sf::Time::Zero;
    }
  }
}

void HoverHub::checkContains()
{
  sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);

  // PlayerView
  sf::Vector2f mouseWorldPosition = m_window.mapPixelToCoords(mousePosition, m_playerView);
  loopItemsAndCheckContains(m_floorItems.getDices(), mouseWorldPosition);
  loopItemsAndCheckContains(m_floorItems.getWeapons(), mouseWorldPosition);

  // UiView
  mouseWorldPosition = m_window.mapPixelToCoords(mousePosition, m_uiView);
  loopItemsAndCheckContains(m_inventory.getDices(), mouseWorldPosition);
  loopItemsAndCheckContains(m_inventory.getWeapons(), mouseWorldPosition);
}

void HoverHub::handleElapsedTime(sf::Time &delta)
{
  m_elapsedTime += delta;
  if (m_elapsedTime.asSeconds() >= m_showUpTime)
  {
    m_toolTip.setIsActive(false);
  }
}
