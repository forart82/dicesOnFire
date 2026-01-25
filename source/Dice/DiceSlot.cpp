#include <SFML/Graphics.hpp>
#include "Dice/DiceSlot.h"
#include "Form/BaseCircle.h"

DiceSlot::DiceSlot()
    : BaseCircle()
{
}

DiceSlot::DiceSlot(BaseCircle diceSlotMenu)
    : m_diceSlotMenu(diceSlotMenu)
{
}

DiceSlot::~DiceSlot()
{
}