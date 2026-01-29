#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "_GLOBALS.h"
#include "_HELPERS.h"
#include "_COLORS.h"

Grid::Grid()
{
  int numCells = (GLOBAL_SCREEN_WIDTH / TILE_SIZE) * (GLOBAL_SCREEN_HEIGHT / TILE_SIZE);
  m_cells.reserve(numCells); // Reserve memory to avoid reallocations
  m_vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
  m_vertices.resize(numCells * 6);
  createStartZone();
  // m_transform.rotate(sf::degrees(45.f));
  m_transform.scale({1.f, 0.5f});
}
Grid::~Grid() {}

void Grid::createStartZone()
{
  int cellCounter = 0;

  for (int height = SNAP_TO_GRID(SCOREBOARD_HEIGHT); height < GLOBAL_SCREEN_HEIGHT; height += TILE_SIZE)
  {
    for (int width = SNAP_TO_GRID(0); width < GLOBAL_SCREEN_WIDTH; width += TILE_SIZE)
    {
      // Get a pointer to the first vertex of the current quad
      sf::Vertex *triangels = &m_vertices[cellCounter * 6];
      // Use emplace_back to construct the Cell in-place
      m_cells.emplace_back(triangels, sf::Vector2f(width, height), colors::COLOR_BROWN_MILKY_SAND);
      cellCounter++;
    }
  }
}

void Grid::update(sf::Time &delta)
{
  // Future grid update logic
}

void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  states.transform *= m_transform;
  target.draw(m_vertices, states);
}