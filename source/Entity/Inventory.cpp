#include "Entity/Inventory.h"

Inventory::Inventory()
    : VertexRectangle(
          0,
          0,
          0,
          0),
      m_size(25),
      m_isActive(false)
{
  m_texture = &textureLoader::getTexture("Utumno");
  makeInventory();
}
Inventory::~Inventory()
{
}

void Inventory::update(sf::Time &delta) {}

void Inventory::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if (m_isActive)
  {
    states.texture = m_texture;
    target.draw(m_vertices, states);
  }
}

void Inventory::makeInventory()
{
  sf::Vector2f inventoryPosition = configLoader::get<sf::Vector2f>("INVENTORY_POSITION");
  int x = inventoryPosition.x;
  int y = inventoryPosition.y;
  int tileSize = configLoader::get<int>("TILE_SIZE");
  int assetsLeft = 928;
  int assetsTop = 1600;
  for (int i = 1; i <= m_size; i++)
  {
    if (i % 5 == 0)
    {
      x = inventoryPosition.x;
      y += tileSize;
    }
    m_cells.emplace_back(std::make_unique<Cell>(x, y, assetsLeft, assetsTop));
    x += tileSize;
  }
}

void Inventory::toggleInventory()
{
  m_isActive != m_isActive;
}

std::vector<std::unique_ptr<Cell>> &Inventory::getCells()
{
  return m_cells;
}

int Inventory::getCellsSize() const
{
  return m_cells.size();
}

bool Inventory::getIsActive() const
{
  return m_isActive;
}