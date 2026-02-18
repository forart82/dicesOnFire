#include "Entity/Inventory.h"

Inventory::Inventory()
    : m_size(configLoader::get<int>("INVENTORY_SIZE")),
      m_sizeMod(configLoader::get<int>("INVENTORY_SIZE_MOD")),
      m_tileSize(configLoader::get<int>("TILE_SIZE")),
      m_isActive(false),
      m_inventoryPosition(configLoader::get<sf::Vector2f>("INVENTORY_POSITION"))
{
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
  }
}

void Inventory::addDice(std::unique_ptr<Dice> dice)
{
  int freeSlotIndex = getFreeSlotIndex();
  if (freeSlotIndex >= 0)
  {
    placeItem(dice, freeSlotIndex);
    Dice *dicePtr = dice.get();
    m_slots[freeSlotIndex].dice = dicePtr;
    Items::addDice(std::move(dice));
  }
}

void Inventory::addWeapon(std::unique_ptr<Weapon> weapon)
{
  int freeSlotIndex = getFreeSlotIndex();
  if (freeSlotIndex >= 0)
  {
    placeItem(weapon, freeSlotIndex);
    Weapon *weaponPtr = weapon.get();
    m_slots[freeSlotIndex].weapon = weaponPtr;
    Items::addWeapon(std::move(weapon));
  }
}

template <typename T>
void Inventory::placeItem(T &item, int &freeSlotIndex)
{
  int column = freeSlotIndex % m_sizeMod;
  int row = freeSlotIndex / m_sizeMod + 1;
  item->resetLeftTop(
      sf::Vector2f(m_inventoryPosition.x + (column * m_tileSize),
                   m_inventoryPosition.y + (row * m_tileSize)));
}

void Inventory::makeInventory()
{
  int x = m_inventoryPosition.x;
  int y = m_inventoryPosition.y;
  int assetsLeft = 928;
  int assetsTop = 1600;
  for (int i = 0; i <= m_size - 1; i++)
  {
    if (i % m_sizeMod == 0)
    {
      x = m_inventoryPosition.x;
      y += m_tileSize;
    }
    m_cells.emplace_back(std::make_unique<Cell>(x, y, assetsLeft, assetsTop));
    x += m_tileSize;
  }
  m_slots.resize(m_size);
}

void Inventory::toggleInventory()
{
  m_isActive = !m_isActive;
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

int Inventory::getFreeSlotIndex()
{
  int freeSlotIndex = -1;
  for (size_t i = 0; i < m_slots.size(); ++i)
  {
    if (m_slots[i].isEmpty())
    {
      freeSlotIndex = i;
      break;
    }
  }
  return freeSlotIndex;
}