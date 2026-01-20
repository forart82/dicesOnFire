#include <SFML/Graphics.hpp>
#include "../header/Sword.h"
#include "../header/_BaseWeapon.h"

Sword::Sword()
    : Sword(7, 2) {}

Sword::Sword(int damage, int numberOfSlots)
    : _BaseWeapon(damage, numberOfSlots) {}

Sword::~Sword() {};

void Sword::update(sf::Time &delta)
{
  _BaseWeapon::update(delta);
}

void Sword::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  _BaseWeapon::draw(target, states);
}