#pragma once

#include "Ability/VertexRectangleDrawable.h"
#include "Entity/Game.h"
#include "Entity/BaseItems.h"
#include "Entity/Cell.h"
#include "Loader/ConfigLoader.h"

class Dice;
class BaseWEapon;
class Inventory : public BaseItems
{
private:
  struct SlotContent
  {
    Dice *dice = nullptr;             // Pointer to dice if present
    BaseWeapon *baseWeapon = nullptr; // Pointer to weapon if present

    bool isEmpty() const { return dice == nullptr && baseWeapon == nullptr; }
  };

  std::vector<std::unique_ptr<Cell>> m_cells;
  std::vector<SlotContent> m_slots;
  sf::Vector2f m_inventoryPosition;
  int m_size;
  int m_sizeMod;
  int m_tileSize;
  bool m_isActive;

public:
  Inventory();
  ~Inventory();

  void update(sf::Time &delta) override;
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void addDice(std::unique_ptr<Dice> dice);
  void addWeapon(std::unique_ptr<BaseWeapon> baseWeapon);

  template <typename T>
  void placeItem(const T &item, int freeSlotIndex);

  void makeInventory();
  void toggleInventory();

  const std::vector<std::unique_ptr<Cell>> &getCells() const;
  int getCellsSize() const;
  int getFreeSlotIndex() const;
  bool getIsActive() const;
};