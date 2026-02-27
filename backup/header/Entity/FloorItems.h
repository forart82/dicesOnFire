#pragma once

#include "Ability/VertexRectangleDrawable.h"
#include "Entity/BaseItems.h"

class FloorItems : public BaseItems, public VertexRectangleDrawable
{
private:
public:
  FloorItems();
  ~FloorItems();

  void update(sf::Time &delta) override;
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};