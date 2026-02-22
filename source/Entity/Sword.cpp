#include "Entity/Sword.h"

Sword::Sword()
    : BladedWeapon(game),
      m_game(game)
{
}

Sword::~Sword() {};

void Sword::update(sf::Time &delta)
{
  BladedWeapon::update(delta);
}

void Sword::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  BladedWeapon::draw(target, states);
}