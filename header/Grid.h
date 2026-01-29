#pragma once

#include "Cell.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Grid : public sf::Drawable
{

private:
  std::vector<Cell> m_cells;
  sf::VertexArray m_vertices;
  sf::Transform m_transform;

public:
  Grid();
  ~Grid();

  void createStartZone();

  void update(sf::Time &detla);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};