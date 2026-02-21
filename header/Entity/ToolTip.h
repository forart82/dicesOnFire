#pragma once

#include <SFML/Graphics.hpp>
#include "Ability/VertexRectangleDrawable.h"
#include "Loader/TextureLoader.h"
#include "Loader/FontLoader.h"

class ToolTip : public sf::Drawable, public VertexRectangleDrawable
{
private:
  sf::Text m_title;
  sf::Text m_stats;

public:
  ToolTip();
  ~ToolTip();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void setTitle(const std::string &title);
  void setStats(const std::string &stats);
};