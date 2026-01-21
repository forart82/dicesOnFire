#include <SFML/Graphics.hpp>
#include "Weapon/BladedWeapon.h"
#include "Weapon/_BaseWeapon.h"

BladedWeapon::BladedWeapon()
    : BladedWeapon(7, 2) {}

BladedWeapon::BladedWeapon(int damage, int numberOfSlots)
    : _BaseWeapon(damage, numberOfSlots) {}

BladedWeapon::~BladedWeapon() {};

void BladedWeapon::update(sf::Time &delta)
{
  _BaseWeapon::update(delta);
}

void BladedWeapon::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  _BaseWeapon::draw(target, states);
}