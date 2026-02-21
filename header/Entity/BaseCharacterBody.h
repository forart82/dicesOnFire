#pragma once

#include <SFML/Graphics.hpp>
#include "Ability/VertexRectangleDrawable.h"
#include "Entity/Rectangle.h"
#include "Entity/RectangleX2.h"
#include "Entity/Circle.h"
#include "Helper/CollisionHelper.h"

class BaseCharacterBody : public sf::Drawable, public VertexRectangleDrawable
{
protected:
  Game &m_game;

  std::unique_ptr<Rectangle> m_body;
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
  BaseCharacterBody(Game &game);
  ~BaseCharacterBody();

  virtual void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void move(sf::Vector2f &movement);

  bool insideWatchRangeCircle(const sf::Vector2f &targetPos) const;
  bool insideShortRangeCircle(const sf::Vector2f &targetPos) const;
  bool insideLongRangeCircle(const sf::Vector2f &targetPos) const;
  bool insidePickUpRangeCircle(const sf::Vector2f &targetPos) const;

  void toggleDebugIsActive();

  void setBody(std::unique_ptr<Rectangle> body);
  void setHealthBar(std::unique_ptr<RectangleX2> healthBar);
  void setWatchRangeCircle(std::unique_ptr<Circle> watchRangeCircle);
  void setShortRangeCircle(std::unique_ptr<Circle> shortRangeCircle);
  void setLongRangeCircle(std::unique_ptr<Circle> longRangeCircle);
  void setPickUpRangeCircle(std::unique_ptr<Circle> pickUpRangeCircle);
  void setHealth(float health);
  void setMaxHealth(float maxHealth);
  void setSpeed(float speed);
  void setWatchRangeRadius(int watchRangeRadius);
  void setShortRangeRadius(int shortRangeRadius);
  void setLongRangeRadius(int longRangeRadius);
  void setPickUpRangeRadius(int pickUpRangeRadius);

  const Rectangle &getBody() const;
  const RectangleX2 &getHealthBar() const;
  const Circle &getWatchRangeCircle() const;
  const Circle &getShortRangeCircle() const;
  const Circle &getLongRangeCircle() const;
  const Circle &getPickUpRangeCircle() const;
  float getHealth() const;
  float getMaxHealth() const;
  float getSpeed() const;
  int getWatchRangeRadius() const;
  int getShortRangeRadius() const;
  int getLongRangeRadius() const;
  int getPickUpRangeRadius() const;
};