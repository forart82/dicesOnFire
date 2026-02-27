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
      m_tileSize(m_game->getConfigLoader().get<int>("TILE_SIZE"))
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

  if (item->getIsActive())
  {
    // Triangle 1
    triangels[0].position = item->getVertexBodyLeftTop();
    triangels[1].position = item->getVertexBodyRightTop();
    triangels[2].position = item->getVertexBodyLeftBottom();

    // Triangle 2
    triangels[3].position = item->getVertexBodyRightTop();
    triangels[4].position = item->getVertexBodyRightBottom();
    triangels[5].position = item->getVertexBodyLeftBottom();

    // Triangle 1
    triangels[0].texCoords = item->getVertexAssetBodyLeftTop();
    triangels[1].texCoords = item->getVertexAssetBodyRightTop();
    triangels[2].texCoords = item->getVertexAssetBodyLeftBottom();

    // Triangle 2
    triangels[3].texCoords = item->getVertexAssetBodyRightTop();
    triangels[4].texCoords = item->getVertexAssetBodyRightBottom();
    triangels[5].texCoords = item->getVertexAssetBodyLeftBottom();

    m_verticesCounter++;
  }
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
    states.texture = m_game->getTextureLoader().getTexture("Utumno");
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

  int playerXMin = gridHelper::SNAP_TO_GRID(heroPosition.x - heroWatchRangeRadius * m_tileSize, m_tileSize);
  int playerYMin = gridHelper::SNAP_TO_GRID(heroPosition.y - heroWatchRangeRadius * m_tileSize, m_tileSize);

  int playerXMax = gridHelper::SNAP_TO_GRID(heroPosition.x + heroWatchRangeRadius * m_tileSize, m_tileSize);
  int playerYMax = gridHelper::SNAP_TO_GRID(heroPosition.y + heroWatchRangeRadius * m_tileSize, m_tileSize);

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