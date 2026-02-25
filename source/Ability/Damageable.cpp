#include "Ability/Damageable.h"

void Damageable::bind(Rectangle *body, RectangleX2 *healthBar)
{
  m_damageableBody = body;
  m_damageableHealthBar = healthBar;
}

void Damageable::takeDamage(int amount)
{
  m_health -= amount;
}

void Damageable::setHealth(float health)
{
  m_health = health;
}
void Damageable::setMaxHealth(float maxHealth)
{
  m_maxHealth = maxHealth;
}

const sf::Vector2f &Damageable::getBodyPosition() const
{
  return m_damageableBody->getShape().getPosition();
}

float Damageable::getHealth() const
{
  return m_health;
}
float Damageable::getMaxHealth() const
{
  return m_maxHealth;
}

bool Damageable::isAlive() const
{
  return m_health > 0;
}