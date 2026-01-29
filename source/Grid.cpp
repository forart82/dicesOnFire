#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "_GLOBALS.h"
#include "_HELPERS.h"
#include "_COLORS.h"
#include "Manager/TextureManager.h"

Grid::Grid(Hero &hero)
    : m_hero(hero)
{
  int numCells = 2500;
  m_vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
  m_vertices.resize(numCells * 6);
  createStartZone();
}
Grid::~Grid() {}

void Grid::update(sf::Time &delta)
{
  // m_vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
  // m_vertices.resize(2500 * 6);
  // createStartZone();
}

void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  states.texture = &textureManager::getTexture("Utumno");
  target.draw(m_vertices, states);
}

void Grid::createStartZone()
{
  int cellCounter = 0;
  int radius = 25;
  int playerXMin = SNAP_TO_GRID(m_hero.getBody().getShape().getPosition().x - radius * TILE_SIZE);
  int playerYMin = SNAP_TO_GRID(m_hero.getBody().getShape().getPosition().y - radius * TILE_SIZE);

  int playerXMax = SNAP_TO_GRID(m_hero.getBody().getShape().getPosition().x + radius * TILE_SIZE);
  int playerYMax = SNAP_TO_GRID(m_hero.getBody().getShape().getPosition().y + radius * TILE_SIZE);

  for (int x = playerXMin; x <= playerXMax; x += TILE_SIZE)
  {
    for (int y = playerYMin; y <= playerYMax; y += TILE_SIZE)
    {

      if (m_cells.find({x, y}) == m_cells.end())
      {
        sf::Vertex *triangels = &m_vertices[cellCounter * 6];
        m_cells.try_emplace({x, y}, triangels, sf::Vector2f(x, y), colors::COLOR_BROWN_MILKY_SAND);
        std::cout << cellCounter << std::endl;
      }

      cellCounter++;
    }
  }
}