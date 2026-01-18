#include <SFML/Graphics.hpp>
#include "../header/DiceSlot.h"
#include "../header/_BaseCircle.h"

DiceSlot::DiceSlot()
    : _BaseCircle()
{
}

DiceSlot::DiceSlot(sf::Vector2f position, float radius, sf::Color fillColor, sf::Color outlineColor, bool isActive)
    : _BaseCircle(position, radius, fillColor, outlineColor, isActive)
{
}

DiceSlot::~DiceSlot()
{
}