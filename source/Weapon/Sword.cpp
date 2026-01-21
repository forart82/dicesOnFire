#include <SFML/Graphics.hpp>
#include "Weapon/Sword.h"
#include "Weapon/BladedWeapon.h"

Sword::Sword()
    : Sword(7, 2) {}

Sword::Sword(int damage, int numberOfSlots)
    : BladedWeapon(damage, numberOfSlots) {}

Sword::~Sword() {};

void Sword::update(sf::Time &delta)
{
  BladedWeapon::update(delta);
}

void Sword::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  BladedWeapon::draw(target, states);
}