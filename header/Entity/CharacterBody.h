#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Rectangle.h"
#include "Entity/RectangleX2.h"
#include "Entity/Circle.h"
#include "Helper/CollisionHelper.h"

class CharacterBody : public sf::Drawable
{
protected:
  std::unique_ptr<Rectangle> m_bodyBox;
  std::unique_ptr<RectangleX2> m_healthBar;
  std::unique_ptr<Circle> m_watchRangeCircle;
  std::unique_ptr<Circle> m_shortRangeCircle;
  std::unique_ptr<Circle> m_longRangeCircle;
  std::unique_ptr<Circle> m_pickUpRangeCircle;
  float m_health;
  float m_maxHealth;
  float m_speed;

  int m_watchRangeRadius;
  int m_shortRangeRadius;
  int m_longRangeRadius;
  int m_pickUpRangeRadius;

  bool m_debugIsActive;

public:
  CharacterBody();
  CharacterBody(
      std::unique_ptr<Rectangle> bodyBox,
      std::unique_ptr<RectangleX2> healthBar,
      std::unique_ptr<Circle> watchRangeCircle,
      std::unique_ptr<Circle> shortRangeCircle,
      std::unique_ptr<Circle> longRangeCircle,
      std::unique_ptr<Circle> pickUpRangeCircle,
      float health,
      float maxHealth,
      float speed,
      int watchRangeRadius,
      int shortRangeRadius,
      int longRangeRadius,
      int pickUpRangeRadius);
  ~CharacterBody();

  virtual void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void move(sf::Vector2f &movement);

  bool insideWatchRangeCircle(const sf::Vector2f &targetPos);
  bool insideShortRangeCircle(const sf::Vector2f &targetPos);
  bool insideLongRangeCircle(const sf::Vector2f &targetPos);
  bool insidePickUpRangeCircle(const sf::Vector2f &targetPos);

  void setBody(std::unique_ptr<Rectangle> bodyBox);
  void setHealthBar(std::unique_ptr<RectangleX2> healthBar);
  void setHealth(float health);
  void setMaxHealth(float maxHealth);
  void setSpeed(float speed);
  void setWatchRangeRadius(int watchRangeRadius);
  void setPickUpRangeRadius(int watchRangeRadius);

  void toggleDebugIsActive();

  Rectangle &getBody();
  RectangleX2 &getHealthBar();
  Circle &getWatchRangeCircle();
  Circle &getShortRangeCircle();
  Circle &getLongRangeCircle();
  Circle &getPickUpRangeCircle();
  float &getHealth();
  float &getMaxHealth();
  float &getSpeed();
  int &getWatchRangeRadius();
  int &getShortRangeRadius();
  int &getLongRangeRadius();
  int &getPickUpRangeRadius();
};