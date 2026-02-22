#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Game.h"
#include "Entity/Circle.h"

class DiceSlot : public sf::Drawable
{
private:
public:
  DiceSlot();
  ~DiceSlot();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};