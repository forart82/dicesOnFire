#include "Ability/Damageable.h"

void Damageable::takeDamage(int amount)
{
  m_health -= amount;
}
const Damageable::sf::Vector2f &getPosition()
{
}

bool Damageable::isAlive() const { return m_health > 0; }