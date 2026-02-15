#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Dice.h"
#include "Entity/VertexRectangle.h"
#include "Entity/Weapon.h"
#include "Loader/TextureLoader.h"
#include "Entity/Items.h"

class FloorItems : public Items, public VertexRectangle
{
private:
public:
  FloorItems();
  ~FloorItems();

  void update(sf::Time &delta) override;
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};