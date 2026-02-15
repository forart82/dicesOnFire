#include "Entity/Grid.h"

Grid::Grid() {}
Grid::~Grid() {}

Cell &Grid::findOrMakeCell(int x, int y)
{
  int assetsLeft = 32 * randomHelper::GET_RANDOM_NUMBER_INT(0, 10);
  int assetsTop = 224;
  auto [iterator, was_inserted] = m_cells.try_emplace({x, y}, x, y, assetsLeft, assetsTop);
  return iterator->second;
}
