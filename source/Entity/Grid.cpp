#include "Entity/Grid.h"

Grid::Grid() {}
Grid::~Grid() {}

Cell &Grid::findOrMakeCell(int x, int y)
{
  auto [iterator, was_inserted] = m_cells.try_emplace({x, y}, x, y);
  return iterator->second;
}
