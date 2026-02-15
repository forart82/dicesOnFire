#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity/VertexRectangle.h"
#include "Entity/Dice.h"
#include "Entity/Weapon.h"
#include "Entity/Items.h"
#include "Entity/Cell.h"
#include "Loader/ConfigLoader.h"

class Inventory : public Items, public VertexRectangle
{
private:
  std::vector<std::unique_ptr<Cell>> m_cells;
  int m_size;
  bool m_isActive;

public:
  Inventory();
  ~Inventory();

  void update(sf::Time &delta) override;
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void makeInventory();
  void toggleInventory();

  std::vector<std::unique_ptr<Cell>> &getCells();
  int getCellsSize() const;

  bool getIsActive() const;
};