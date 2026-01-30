#pragma once

#include "Cell.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Entity/Hero.h"

class Grid : public sf::Drawable
{

private:
  std::map<std::pair<int, int>, Cell> m_cells;
  sf::VertexArray m_vertices;
  int m_radius;

  Hero &m_hero;

public:
  Grid(Hero &hero);
  ~Grid();

  void update(sf::Time &detla);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void loadZone();
};