#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Grid.h"
#include "Entity/Enemies.h"
#include "Entity/Hero.h"
#include "Loader/TextureLoader.h"

class VertexHub : public sf::Drawable
{

private:
  sf::VertexArray m_vertices;
  int m_totalVertices;
  int m_verticesCounter;

  Hero &m_hero;
  Grid &m_grid;
  Enemies &m_enemies;

public:
  VertexHub(
      Hero &hero,
      Grid &grid,
      Enemies &Enemies);
  ~VertexHub();

  void update(sf::Time &delta);
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  void initCount();
  void countTotalVertices();
  void countGridVertices();
  void countEnemiesVertices();

  void resizeVertices();
  void gridVertices();
  void enemiesVertices();
};