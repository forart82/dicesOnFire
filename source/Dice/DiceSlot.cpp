#include <SFML/Graphics.hpp>
#include "Dice/DiceSlot.h"
#include "Form/BaseCircle.h"

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