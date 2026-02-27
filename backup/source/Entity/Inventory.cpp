#include "Entity/Inventory.h"

Inventory::Inventory()
    : m_size(m_game->getConfigLoader().get<int>("INVENTORY_SIZE")),
      m_sizeMod(m_game->getConfigLoader().get<int>("INVENTORY_SIZE_MOD")),
      m_tileSize(m_game->getConfigLoader().get<int>("TILE_SIZE")),
      m_inventoryPosition(m_game->getConfigLoader().get<sf::Vector2f>("INVENTORY_POSITION")),
      m_isActive(false)
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
    BaseItems::addDice(std::move(dice));
  }
}

void Inventory::addWeapon(std::unique_ptr<BaseWeapon> weapon)
{
  int freeSlotIndex = getFreeSlotIndex();
  if (freeSlotIndex >= 0)
  {
    placeItem(weapon, freeSlotIndex);
    BaseWeapon *weaponPtr = weapon.get();
    m_slots[freeSlotIndex].baseWeapon = weaponPtr;
    BaseItems::addWeapon(std::move(weapon));
  }
}

template <typename T>
void Inventory::placeItem(const T &item, int freeSlotIndex)
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
    m_cells.emplace_back(m_game->getCellManager().create<Cell>());
    x += m_tileSize;
  }
  m_slots.resize(m_size);
}

void Inventory::toggleInventory()
{
  m_isActive = !m_isActive;
}

const std::vector<std::unique_ptr<Cell>> &Inventory::getCells() const
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
int Inventory::getFreeSlotIndex() const
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