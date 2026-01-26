#pragma once

#include <SFML/Graphics.hpp>
#include "Form/BaseCircle.h"

class DiceSlot : public BaseCircle
{
private:
public:
  DiceSlot();
  DiceSlot(BaseCircle diceSlotMenu);
  ~DiceSlot();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};