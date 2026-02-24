#pragma once

#include "Entity/Rectangle.h"
#include "Entity/RectangleX2.h"

class Damageable
{
protected:
  std::unique_ptr<Rectangle> m_body;
  std::unique_ptr<RectangleX2> m_healthBar;

  float m_health;
  float m_maxHealth;

public:
  Damageable() = default;
  virtual ~Damageable() = default;

  virtual void takeDamage(int amount) = 0;

  virtual void setBody(std::unique_ptr<Rectangle> body) = 0;
  virtual void setHealthBar(std::unique_ptr<RectangleX2> healthBar) = 0;

  virtual void setHealth(float health) = 0;
  virtual void setMaxHealth(float maxHealth) = 0;

  virtual const Rectangle &getBody() const = 0;
  virtual const RectangleX2 &getHealthBar() const = 0;

  virtual const sf::Vector2f &getBodyPosition() const = 0;
  virtual float getHealth() const = 0;
  virtual float getMaxHealth() const = 0;

  bool isAlive() const { return m_health > 0; }
};