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
      m_verticesCounter(0),
      m_tileSize(configLoader::get<int>("TILE_SIZE"))
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

template <typename T>
void VertexHub::loopItemsAndMakeTriangles(const T &items)
{
  for (auto &item : items)
  {
    makeTriangles(item);
  }
}

template <typename T>
void VertexHub::makeTriangles(const T &item)
{
  sf::Vertex *triangels = &m_vertices[m_verticesCounter * 6];

  // Triangle 1
  triangels[0].position = item->getLeftTop();
  triangels[1].position = item->getRightTop();
  triangels[2].position = item->getLeftBottom();

  // Triangle 2
  triangels[3].position = item->getRightTop();
  triangels[4].position = item->getRightBottom();
  triangels[5].position = item->getLeftBottom();

  // Triangle 1
  triangels[0].texCoords = item->getAssetsLeftTop();
  triangels[1].texCoords = item->getAssetsRightTop();
  triangels[2].texCoords = item->getAssetsLeftBottom();

  // Triangle 2
  triangels[3].texCoords = item->getAssetsRightTop();
  triangels[4].texCoords = item->getAssetsRightBottom();
  triangels[5].texCoords = item->getAssetsLeftBottom();

  m_verticesCounter++;
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
  m_totalVertices += m_floorItems.getWeaponSize();
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

  int playerXMin = gridHelper::SNAP_TO_GRID(heroPosition.x - heroWatchRangeRadius * m_tileSize);
  int playerYMin = gridHelper::SNAP_TO_GRID(heroPosition.y - heroWatchRangeRadius * m_tileSize);

  int playerXMax = gridHelper::SNAP_TO_GRID(heroPosition.x + heroWatchRangeRadius * m_tileSize);
  int playerYMax = gridHelper::SNAP_TO_GRID(heroPosition.y + heroWatchRangeRadius * m_tileSize);

  for (int x = playerXMin; x <= playerXMax; x += m_tileSize)
  {
    for (int y = playerYMin; y <= playerYMax; y += m_tileSize)
    {
      auto *cell = &m_grid.findOrMakeCell(x, y);
      makeTriangles(cell);
    }
  }
}

void VertexHub::floorItemsVertices()
{
  loopItemsAndMakeTriangles(m_floorItems.getDices());
  loopItemsAndMakeTriangles(m_floorItems.getWeapons());
}

void VertexHub::enemiesVertices()
{
  loopItemsAndMakeTriangles(m_enemies.getEnemies());
}