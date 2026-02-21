#include "Entity/BladedWeapon.h"

BladedWeapon::BladedWeapon(Game &game)
    : BaseWeapon(game)
{
  makeDiceSlots();
}

BladedWeapon::~BladedWeapon() {};

void BladedWeapon::update(sf::Time &delta)
{
  BaseWeapon::update(delta);
}

void BladedWeapon::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  BaseWeapon::draw(target, states);
}