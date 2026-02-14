#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Grid.h"
#include "Entity/Enemies.h"
#include "Entity/Hero.h"
#include "Entity/FloorItems.h"
#include "Loader/TextureLoader.h"
#include "Loader/ConfigLoader.h"

class VertexHub : public sf::Drawable
{

private:
  sf::VertexArray m_vertices;
  int m_totalVertices;
  int m_verticesCounter;
  int m_tileSize;

  Grid &m_grid;
  FloorItems &m_floorItems;
  Hero &m_hero;
  Enemies &m_enemies;

public:
  VertexHub(
      Grid &grid,
      FloorItems &m_floorItems,
      Hero &hero,
      Enemies &Enemies);
  ~VertexHub();

  void update(sf::Time &delta);
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  template <typename T>
  void loopItemsAndMakeTriangles(const T &items);

  template <typename T>
  void makeTriangles(const T &item);

  void initCount();
  void countTotalVertices();
  void countGridVertices();
  void countFloorItemsVertices();
  void countEnemiesVertices();

  void resizeVertices();
  void gridVertices();
  void floorItemsVertices();
  void enemiesVertices();
};