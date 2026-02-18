#include "Entity/ToolTip.h"

ToolTip::ToolTip()
    : m_title(fontLoader::get("PermanentMarker")),
      m_stats(fontLoader::get("Quantico")),
      VertexRectangle(
          0,
          0,
          928,
          1600)
{
  m_leftTop = sf::Vector2f(100, 100);
  m_rightTop = sf::Vector2f(300, 100);
  m_leftBottom = sf::Vector2f(100, 500);
  m_rightBottom = sf::Vector2f(300, 500);
  m_title.setString("TITLE");
  m_title.setPosition(sf::Vector2f(100, 100));
  m_stats.setString("SOME STATS: \n damage: 10\n speed: 2");
  m_stats.setPosition(sf::Vector2f(100, 200));
}

ToolTip::~ToolTip() {}

void ToolTip::update(sf::Time &delta) {}
void ToolTip::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(m_title);
  target.draw(m_stats);
}