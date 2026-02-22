#include "Entity/ToolTip.h"

ToolTip::ToolTip()
    : m_title(m_game->getFontLoader().get("PermanentMarker")),
      m_stats(m_game->getFontLoader().get("Quantico"))
{
  sf::FloatRect toolTipWindow = m_game->getConfigLoader().get<sf::FloatRect>("TOOLTIP_WINDOW");
  setVertexAssetBodyFloatRect(toolTipWindow);
  setVertexAssetBodyPosition(
      sf::Vector2f(928, 1600));

  m_isActive = false;
  m_title.setString("TITLE");
  m_title.setCharacterSize(m_game->getConfigLoader().get<int>("TOOLTIP_TITLE_SIZE"));
  m_title.setPosition(m_game->getConfigLoader().get<sf::Vector2f>(""));
  m_title.setPosition(sf::Vector2f(100, 100));
  m_stats.setString("SOME STATS: \n damage: 10\n speed: 2");
  m_stats.setCharacterSize(m_game->getConfigLoader().get<int>("TOOLTIP_STATS_SIZE"));
  m_stats.setPosition(m_game->getConfigLoader().get<sf::Vector2f>("TOOLTIP_STATS_POSITION"));
}

ToolTip::~ToolTip() {}

void ToolTip::update(sf::Time &delta) {}
void ToolTip::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if (m_isActive)
  {
    target.draw(m_title);
    target.draw(m_stats);
  }
}

void ToolTip::setTitle(const std::string &title)
{
  m_title.setString(title);
}

void ToolTip::setStats(const std::string &stats)
{
  m_stats.setString(stats);
}