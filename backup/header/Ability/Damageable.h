#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Rectangle.h"
#include "Entity/RectangleX2.h"

class Damageable
{
private:
  Rectangle *m_damageableBody = nullptr;
  RectangleX2 *m_damageableHealthBar = nullptr;

protected:
  float m_health;
  float m_maxHealth;

public:
  Damageable();
  virtual ~Damageable() = default;

  void bind(Rectangle *body, RectangleX2 *healthBar);
  void takeDamage(int amount);

  void setHealth(float health);
  void setMaxHealth(float maxHealth);

  const sf::Vector2f &getDamageableBodyPosition() const;
  float getHealth() const;
  float getMaxHealth() const;

  bool isAlive() const { return m_health > 0; }
};