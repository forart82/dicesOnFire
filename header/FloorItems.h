#pragma once

#include <SFML/Graphics.hpp>
#include "Dice/Dice.h"

class FloorItems : public sf::Drawable
{
private:
  sf::VertexArray m_vertices;
  std::vector<std::unique_ptr<Dice>> m_dices;

public:
  FloorItems();
  ~FloorItems();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void addFloorItem();
};