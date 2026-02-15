#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Inventory.h"
#include "Loader/TextureLoader.h"
#include "Loader/ConfigLoader.h"

class VertexGuiHub : public sf::Drawable
{

private:
  sf::VertexArray m_vertices;
  int m_totalVertices;
  int m_verticesCounter;
  int m_tileSize;

  Inventory &m_inventory;

public:
  VertexGuiHub(
      Inventory &inventory);
  ~VertexGuiHub();

  void update(sf::Time &delta);
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  template <typename T>
  void loopItemsAndMakeTriangles(const T &items);

  template <typename T>
  void makeTriangles(const T &item);

  void initCount();
  void countTotalVertices();
  void countInventoryVertices();

  void resizeVertices();
  void inventoryVertices();
};