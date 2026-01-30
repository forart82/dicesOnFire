#pragma once

#include <SFML/Graphics.hpp>
#include "Form/BaseRectangle.h"
#include "Form/BaseRectangleX2.h"

class BaseEntity : public sf::Drawable
{
protected:
  std::unique_ptr<BaseRectangle> m_body;
  std::unique_ptr<BaseRectangleX2> m_healthBar;
  float m_health;
  float m_maxHealth;
  float m_speed;
  int m_watchRadius;

public:
  BaseEntity();
  BaseEntity(
      std::unique_ptr<BaseRectangle> body,
      std::unique_ptr<BaseRectangleX2> healthBar,
      float health,
      float maxHealth,
      float speed,
      int watchRadius);
  ~BaseEntity();

  virtual void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void setBody(std::unique_ptr<BaseRectangle> body);
  void setHealthBar(std::unique_ptr<BaseRectangleX2> healthBar);
  void setHealth(float health);
  void setMaxHealth(float maxHealth);
  void setSpeed(float speed);
  void setWatchRadius(int watchRadius);

  BaseRectangle &getBody();
  BaseRectangleX2 &getHealthBar();
  float &getHealth();
  float &getMaxHealth();
  float &getSpeed();
  int &getWatchRadius();
};