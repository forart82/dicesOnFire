#pragma once

#include "Entity/BaseEntity.h"
#include "Entity/Circle.h"

class DiceSlot : public Gameable, public sf::Drawable
{
private:
public:
  DiceSlot();
  ~DiceSlot();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};