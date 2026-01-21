#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "_GLOBALS.h"
#include "_HELPERS.h"

Grid::Grid()
{
  int numCells = (GLOBAL_SCREEN_WIDTH / TILE_SIZE) * (GLOBAL_SCREEN_HEIGHT / TILE_SIZE);
  cells.reserve(numCells); // Reserve memory to avoid reallocations
  vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
  vertices.resize(numCells * 6);
  createStartZone();
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
      sf::Vertex *triangels = &vertices[cellCounter * 6];
      // Use emplace_back to construct the Cell in-place
      cells.emplace_back(triangels, sf::Vector2f(width, height), COLOR_GRAYSCALE_BLACK);
      cellCounter++;
    }
  }
}

void Grid::update()
{
  // Future grid update logic
}

void Grid::draw(sf::RenderTarget &target)
{
  // Draw all vertices in a single, efficient draw call
  target.draw(vertices);
}
