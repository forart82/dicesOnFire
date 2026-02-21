#include "Entity/Grid.h"

Grid::Grid(Game &game)
    : m_game(game)
{
}
Grid::~Grid() {}

const Cell &Grid::findOrMakeCell(int x, int y) const
{
  int assetsLeft = 32 * randomHelper::GET_RANDOM_NUMBER_INT(0, 10);
  int assetsTop = 224;
  auto [iterator, was_inserted] = m_cells.try_emplace({x, y}, x, y, assetsLeft, assetsTop);
  return iterator->second;
}
