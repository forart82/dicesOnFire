#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity/VertexRectangle.h"
#include "Entity/Dice.h"
#include "Entity/Weapon.h"
#include "Entity/Items.h"
#include "Entity/Cell.h"
#include "Loader/ConfigLoader.h"

class Inventory : public Items
{
private:
  struct SlotContent
  {
    Dice *dice = nullptr;     // Pointer to dice if present
    Weapon *weapon = nullptr; // Pointer to weapon if present

    bool isEmpty() const { return dice == nullptr && weapon == nullptr; }
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
  void addWeapon(std::unique_ptr<Weapon> weapon);

  template <typename T>
  void placeItem(T &item, int &freeSlotIndex);

  void makeInventory();
  void toggleInventory();

  std::vector<std::unique_ptr<Cell>> &getCells();
  int getCellsSize() const;

  bool getIsActive() const;

  SlotContent &getSlot(int index);

  int getFreeSlotIndex();
};