#include "Entity/Grid.h"

Grid::Grid() {}
Grid::~Grid() {}

Cell &Grid::findOrMakeCell(int x, int y)
{
  if (m_cells.find({x, y}) == m_cells.end())
  {
    m_cells.try_emplace({x, y}, x, y);
  }
  return m_cells.at({x, y});
}
