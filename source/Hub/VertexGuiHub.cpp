#include "Hub/VertexGuiHub.h"

VertexGuiHub::VertexGuiHub(
    Inventory &inventory,
    ToolTip &toolTip)
    : m_inventory(inventory),
      m_toolTip(toolTip),
      m_totalVertices(0),
      m_verticesCounter(0),
      m_tileSize(configLoader::get<int>("TILE_SIZE"))
{
  m_vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
}

VertexGuiHub::~VertexGuiHub() {}

void VertexGuiHub::update(sf::Time &delta)
{
  initCount();

  countTotalVertices();

  resizeVertices();

  inventoryVertices();

  toolTipVertices();
}

template <typename T>
void VertexGuiHub::loopItemsAndMakeTriangles(const T &items)
{
  for (auto &item : items)
  {
    makeTriangles(item);
  }
}

template <typename T>
void VertexGuiHub::makeTriangles(const T &item)
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

void VertexGuiHub::initCount()
{
  m_totalVertices = 0;
  m_verticesCounter = 0;
}

void VertexGuiHub::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if (m_verticesCounter > 0)
  {
    states.texture = &textureLoader::getTexture("Utumno");
    target.draw(&m_vertices[0], m_verticesCounter * 6, sf::PrimitiveType::Triangles, states);
  }

  target.draw(m_toolTip);
}

void VertexGuiHub::countTotalVertices()
{
  countInventoryVertices();
  countToolTipVertices();
}

void VertexGuiHub::countInventoryVertices()
{
  m_totalVertices += m_inventory.getCellsSize();
  m_totalVertices += m_inventory.getDicesSize();
  m_totalVertices += m_inventory.getWeaponSize();
}

void VertexGuiHub::countToolTipVertices()
{
  m_totalVertices += 1;
}

void VertexGuiHub::resizeVertices()
{
  if (m_vertices.getVertexCount() != m_totalVertices * 6)
  {
    m_vertices.resize(m_totalVertices * 6);
  }
}

void VertexGuiHub::inventoryVertices()
{
  if (m_inventory.getIsActive())
  {
    loopItemsAndMakeTriangles(m_inventory.getCells());
    loopItemsAndMakeTriangles(m_inventory.getDices());
    loopItemsAndMakeTriangles(m_inventory.getWeapons());
  }
}

void VertexGuiHub::toolTipVertices()
{
  makeTriangles(&m_toolTip);
}
