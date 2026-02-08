#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity/Cell.h"
#include "Entity/Hero.h"
#include "Helper/GridHelper.h"
#include "Loader/TextureLoader.h"

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

  int getVerticesSize();
};