#pragma once

#include <SFML/Graphics.hpp>
#include "Form/BaseCircle.h"

class DiceSlot : public BaseCircle
{
private:
  BaseCircle m_diceSlotMenu;

public:
  DiceSlot();
  DiceSlot(BaseCircle diceSlotMenu);
  ~DiceSlot();
};