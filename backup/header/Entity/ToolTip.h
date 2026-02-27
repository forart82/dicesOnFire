#pragma once

#include "Ability/VertexRectangleDrawable.h"
#include "Entity/Game.h"
#include "Entity/BaseEntity.h"

class ToolTip : public BaseEntity, public sf::Drawable, public VertexRectangleDrawable
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