#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/VertexRectangle.h"
#include "Loader/FontLoader.h"

class ToolTip : public VertexRectangle
{
private:
  sf::Text m_title;
  sf::Text m_stats;

public:
  ToolTip();
  ~ToolTip();

  void update(sf::Time &delta);
};