#include "Grid.h"

Grid::Grid(Hero &hero)
    : m_hero(hero)
{
  m_radius = m_hero.getWatchRangeRadius();
  m_vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
  loadZone();
}
Grid::~Grid() {}

void Grid::update(sf::Time &delta)
{
  loadZone();
}

void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  states.texture = &textureManager::getTexture("Utumno");
  target.draw(m_vertices, states);
}

void Grid::loadZone()
{
  int side = (m_radius * 2) + 1;
  int numCells = side * side;
  if (m_vertices.getVertexCount() != numCells * 6)
  {
    m_vertices.resize(numCells * 6);
  }
  int cellCounter = 0;
  int playerXMin = helper::SNAP_TO_GRID(m_hero.getBody().getShape().getPosition().x - m_radius * TILE_SIZE);
  int playerYMin = helper::SNAP_TO_GRID(m_hero.getBody().getShape().getPosition().y - m_radius * TILE_SIZE);

  int playerXMax = helper::SNAP_TO_GRID(m_hero.getBody().getShape().getPosition().x + m_radius * TILE_SIZE);
  int playerYMax = helper::SNAP_TO_GRID(m_hero.getBody().getShape().getPosition().y + m_radius * TILE_SIZE);

  for (int x = playerXMin; x <= playerXMax; x += TILE_SIZE)
  {
    for (int y = playerYMin; y <= playerYMax; y += TILE_SIZE)
    {

      if (m_cells.find({x, y}) == m_cells.end())
      {
        m_cells.try_emplace({x, y}, x, y);
      }
      sf::Vertex *triangels = &m_vertices[cellCounter * 6];

      auto &cell = m_cells.at({x, y});
      // Triangle 1
      triangels[0].position = cell.getLeftTop();
      triangels[1].position = cell.getRightTop();
      triangels[2].position = cell.getLeftBottom();

      // Triangle 2
      triangels[3].position = cell.getRightTop();
      triangels[4].position = cell.getRightBottom();
      triangels[5].position = cell.getLeftBottom();

      triangels[0].texCoords = cell.getAssetsLeftTop();
      triangels[1].texCoords = cell.getAssetsRightTop();
      triangels[2].texCoords = cell.getAssetsLeftBottom();

      // Triangle 2
      triangels[3].texCoords = cell.getAssetsRightTop();
      triangels[4].texCoords = cell.getAssetsRightBottom();
      triangels[5].texCoords = cell.getAssetsLeftBottom();

      cellCounter++;
    }
  }
}

int Grid::getVerticesSize()
{
  return m_vertices.getVertexCount();
}