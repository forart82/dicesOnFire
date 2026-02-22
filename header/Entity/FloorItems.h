#pragma once

#include <SFML/Graphics.hpp>
#include "Ability/VertexRectangleDrawable.h"
#include "Entity/Game.h"
#include "Entity/Dice.h"
#include "Entity/BaseWeapon.h"
#include "Loader/TextureLoader.h"
#include "Entity/Items.h"

class FloorItems : public Items, public VertexRectangleDrawable
{
private:
public:
  FloorItems();
  ~FloorItems();

  void update(sf::Time &delta) override;
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};