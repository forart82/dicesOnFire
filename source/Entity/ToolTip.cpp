#include "Entity/ToolTip.h"

ToolTip::ToolTip()
    : m_title(fontLoader::get("PermanentMarker")),
      m_stats(fontLoader::get("Quantico")),
      VertexRectangle(
          0,
          0,
          0,
          0)
{
}

ToolTip::~ToolTip() {}

void ToolTip::update(sf::Time &delta) {}