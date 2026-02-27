#include "Ability/Hoverable.h"

Hoverable::Hoverable()
    : m_hoverableShowUpTime(0) {}

void Hoverable::bind(
    ToolTip *hoverableToolTip,
    sf::View *hoverablePlayerView,
    sf::View *hoverableUiView,
    sf::RenderWindow *hoverableWindow)
{
  m_hoverableToolTip = hoverableToolTip;
  m_hoverablePlayerView = hoverablePlayerView;
  m_hoverableUiView = hoverableUiView;
  m_hoverableWindow = hoverableWindow;
}

void Hoverable::update(const sf::Time &delta)
{
  checkHoverOverItem();
}

void Hoverable::checkHoverOverItem()
{
  sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_hoverableWindow);
  // PlayerView
  sf::Vector2f mouseWorldPosition = m_hoverableWindow->mapPixelToCoords(mousePosition, *m_hoverablePlayerView);
  if (this->getGlobalBounds().contains(mouseWorldPosition))
  {
    m_hoverableToolTip->setTitle(this->getName());
    m_hoverableToolTip->setStats(this->getStats());
    m_hoverableToolTip->setIsActive(true);
    m_hoverableElapsedTime = sf::Time::Zero;
  }
}
void Hoverable::resetToolTip(const sf::Time &delta)
{
  m_hoverableElapsedTime += delta;
  if (m_hoverableElapsedTime.asSeconds() >= m_hoverableShowUpTime)
  {
    m_hoverableToolTip->setIsActive(false);
  }
}
