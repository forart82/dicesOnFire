#pragma once

#include <SFML/Graphics.hpp>
#include "Form/BaseRectangle.h"
#include "Form/BaseRectangleX2.h"
#include "Form/BaseCircle.h"

class BaseEntity : public sf::Drawable
{
protected:
  std::unique_ptr<BaseRectangle> m_body;
  std::unique_ptr<BaseRectangleX2> m_healthBar;
  std::unique_ptr<BaseCircle> m_watchRangeCircle;
  std::unique_ptr<BaseCircle> m_shortRangeCircle;
  std::unique_ptr<BaseCircle> m_longRangeCircle;
  float m_health;
  float m_maxHealth;
  float m_speed;
  int m_watchRangeRadius;

  int m_shortRangeRadius;
  int m_longRangeRadius;

public:
  BaseEntity();
  BaseEntity(
      std::unique_ptr<BaseRectangle> body,
      std::unique_ptr<BaseRectangleX2> healthBar,
      std::unique_ptr<BaseCircle> watchRangeCircle,
      std::unique_ptr<BaseCircle> shortRangeCircle,
      std::unique_ptr<BaseCircle> longRangeCircle,
      float health,
      float maxHealth,
      float speed,
      int watchRangeRadius,
      int shortRangeRadius,
      int longRangeRadius);
  ~BaseEntity();

  virtual void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void move(sf::Vector2f &movement);

  bool insideWatchRangeCircle(const sf::Vector2f &targetPos, BaseCircle &radarPtr);
  bool insideShortRangeCircle(const sf::Vector2f &targetPos, BaseCircle &radarPtr);
  bool insideLongRangeCircle(const sf::Vector2f &targetPos, BaseCircle &radarPtr);
  bool insideRadar(const sf::Vector2f &targetPos, BaseCircle &radarPtr);

  void setBody(std::unique_ptr<BaseRectangle> body);
  void setHealthBar(std::unique_ptr<BaseRectangleX2> healthBar);
  void setHealth(float health);
  void setMaxHealth(float maxHealth);
  void setSpeed(float speed);
  void setWatchRangeRadius(int watchRangeRadius);

  BaseRectangle &getBody();
  BaseRectangleX2 &getHealthBar();
  BaseCircle &getWatchRangeCircle();
  BaseCircle &getShortRangeCircle();
  BaseCircle &getLongRangeCircle();
  float &getHealth();
  float &getMaxHealth();
  float &getSpeed();
  int &getWatchRangeRadius();
  int &getShortRangeRadius();
  int &getLongRangeRadius();
};