#include "Entity/Grid.h"

Grid::Grid() {}
Grid::~Grid() {}

const Cell &Grid::findOrMakeCell(int x, int y)
{
  int vertexAssetBodyLeft = 32 * randomHelper::GET_RANDOM_NUMBER_INT(0, 10);
  int vertexAssetBodyTop = 224;
  auto [iterator, was_inserted] = m_cells.try_emplace({x, y});
  if (was_inserted)
  {
    iterator->second.setGame(m_game);
    iterator->second.setVertexAssetBodyPosition(
        sf::Vector2f(vertexAssetBodyLeft, vertexAssetBodyTop));
  }
  return iterator->second;
}
