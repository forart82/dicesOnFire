#include "Dice/DiceSlot.h"

DiceSlot::DiceSlot()
    : BaseCircle()
{
}

DiceSlot::DiceSlot(BaseCircle diceSlotMenu)
    : BaseCircle(diceSlotMenu)
{
}

DiceSlot::~DiceSlot()
{
}

void DiceSlot::update(sf::Time &delta)
{
    BaseCircle::update(delta);
}

void DiceSlot::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    BaseCircle::draw(target, states);
};