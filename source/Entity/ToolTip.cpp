#include "Entity/ToolTip.h"

ToolTip::ToolTip()
    : m_title(fontLoader::get("PermanentMarker")),
      m_stats(fontLoader::get("Quantico")),
      VertexRectangleDrawable(
          0,
          0,
          928,
          1600)
{
  sf::FloatRect tooltipWindow = configLoader::get<sf::FloatRect>("TOOLTIP_WINDOW");
  m_leftTop = sf::Vector2f(tooltipWindow.position.x, tooltipWindow.position.y);
  m_rightTop = sf::Vector2f(tooltipWindow.size.x, tooltipWindow.position.y);
  m_leftBottom = sf::Vector2f(tooltipWindow.position.x, tooltipWindow.size.y);
  m_rightBottom = sf::Vector2f(tooltipWindow.size.x, tooltipWindow.size.y);
  m_isActive = false;
  m_title.setString("TITLE");
  m_title.setCharacterSize(configLoader::get<int>("TOOLTIP_TITLE_SIZE"));
  m_title.setPosition(configLoader::get<sf::Vector2f>(""));
  m_title.setPosition(sf::Vector2f(100, 100));
  m_stats.setString("SOME STATS: \n damage: 10\n speed: 2");
  m_stats.setCharacterSize(configLoader::get<int>("TOOLTIP_STATS_SIZE"));
  m_stats.setPosition(configLoader::get<sf::Vector2f>("TOOLTIP_STATS_POSITION"));
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