#include "Hub/VertextHub.h"

VertexHub::VertexHub(
    Grid &grid,
    FloorItems &floorItems,
    Hero &hero,
    Enemies &enemies)
    : m_grid(grid),
      m_floorItems(floorItems),
      m_hero(hero),
      m_enemies(enemies),
      m_totalVertices(0),
      m_verticesCounter(0)
{
  m_vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
}

VertexHub::~VertexHub() {}

void VertexHub::update(sf::Time &delta)
{
  initCount();

  countTotalVertices();

  resizeVertices();

  gridVertices();

  floorItemsVertices();

  enemiesVertices();
}

void VertexHub::initCount()
{
  m_totalVertices = 0;
  m_verticesCounter = 0;
}

void VertexHub::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if (m_verticesCounter > 0)
  {

    states.texture = &textureLoader::getTexture("Utumno");
    target.draw(&m_vertices[0], m_verticesCounter * 6, sf::PrimitiveType::Triangles, states);
  }
}

void VertexHub::countTotalVertices()
{
  countGridVertices();
  countFloorItemsVertices();
  countEnemiesVertices();
}

void VertexHub::countGridVertices()
{
  int side = (m_hero.getWatchRangeRadius() * 2) + 1;
  m_totalVertices += side * side;
}

void VertexHub::countFloorItemsVertices()
{
  m_totalVertices += m_floorItems.getDicesSize();
}

void VertexHub::countEnemiesVertices()
{
  m_totalVertices += m_enemies.getEnemies().size();
}

void VertexHub::resizeVertices()
{
  if (m_vertices.getVertexCount() != m_totalVertices * 6)
  {
    m_vertices.resize(m_totalVertices * 6);
  }
}

void VertexHub::gridVertices()
{
  auto heroPosition = m_hero.getBody().getShape().getPosition();
  auto heroWatchRangeRadius = m_hero.getWatchRangeRadius();

  int playerXMin = gridHelper::SNAP_TO_GRID(heroPosition.x - heroWatchRangeRadius * globals::TILE_SIZE);
  int playerYMin = gridHelper::SNAP_TO_GRID(heroPosition.y - heroWatchRangeRadius * globals::TILE_SIZE);

  int playerXMax = gridHelper::SNAP_TO_GRID(heroPosition.x + heroWatchRangeRadius * globals::TILE_SIZE);
  int playerYMax = gridHelper::SNAP_TO_GRID(heroPosition.y + heroWatchRangeRadius * globals::TILE_SIZE);

  for (int x = playerXMin; x <= playerXMax; x += globals::TILE_SIZE)
  {
    for (int y = playerYMin; y <= playerYMax; y += globals::TILE_SIZE)
    {

      auto &cell = m_grid.findOrMakeCell(x, y);

      sf::Vertex *triangels = &m_vertices[m_verticesCounter * 6];

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

      m_verticesCounter++;
    }
  }
}

void VertexHub::floorItemsVertices()
{
  for (auto &dice : m_floorItems.getDices())
  {
    sf::Vertex *triangels = &m_vertices[m_verticesCounter * 6];

    triangels[0].position = dice->getLeftTop();
    triangels[1].position = dice->getRightTop();
    triangels[2].position = dice->getLeftBottom();

    // Triangle 2
    triangels[3].position = dice->getRightTop();
    triangels[4].position = dice->getRightBottom();
    triangels[5].position = dice->getLeftBottom();

    triangels[0].texCoords = dice->getAssetsLeftTop();
    triangels[1].texCoords = dice->getAssetsRightTop();
    triangels[2].texCoords = dice->getAssetsLeftBottom();

    // Triangle 2
    triangels[3].texCoords = dice->getAssetsRightTop();
    triangels[4].texCoords = dice->getAssetsRightBottom();
    triangels[5].texCoords = dice->getAssetsLeftBottom();

    m_verticesCounter++;
  }
}

void VertexHub::enemiesVertices()
{
  for (auto &enemy : m_enemies.getEnemies())
  {
    sf::Vertex *triangels = &m_vertices[m_verticesCounter * 6];
    triangels[0].position = enemy->getLeftTop();
    triangels[1].position = enemy->getRightTop();
    triangels[2].position = enemy->getLeftBottom();

    // Triangle 2
    triangels[3].position = enemy->getRightTop();
    triangels[4].position = enemy->getRightBottom();
    triangels[5].position = enemy->getLeftBottom();

    triangels[0].texCoords = enemy->getAssetsLeftTop();
    triangels[1].texCoords = enemy->getAssetsRightTop();
    triangels[2].texCoords = enemy->getAssetsLeftBottom();

    // Triangle 2
    triangels[3].texCoords = enemy->getAssetsRightTop();
    triangels[4].texCoords = enemy->getAssetsRightBottom();
    triangels[5].texCoords = enemy->getAssetsLeftBottom();

    m_verticesCounter++;
  }
}