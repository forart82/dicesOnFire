#pragma once

#include <cmath>

#include "Ability/VertexRectangleDrawable.h"
#include "Ability/Damageable.h"
#include "Ability/Moveable.h"
#include "Entity/BaseEntity.h"
#include "Entity/Rectangle.h"
#include "Entity/RectangleX2.h"
#include "Entity/Circle.h"
#include "Helper/CollisionHelper.h"

class BaseCharacterBody
    : public BaseEntity,
      public sf::Drawable,
      public VertexRectangleDrawable,
      public Damageable,
      public Moveable
{
protected:
  std::unique_ptr<Rectangle> m_body;
  std::unique_ptr<RectangleX2> m_healthBar;
  std::unique_ptr<Circle> m_watchRangeCircle;
  std::unique_ptr<Circle> m_shortRangeCircle;
  std::unique_ptr<Circle> m_longRangeCircle;
  std::unique_ptr<Circle> m_pickUpRangeCircle;

  int m_watchRangeRadius;
  int m_shortRangeRadius;
  int m_longRangeRadius;
  int m_pickUpRangeRadius;

  bool m_debugIsActive;

public:
  BaseCharacterBody();
  virtual ~BaseCharacterBody() = default;

  virtual void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

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

  int getWatchRangeRadius() const;
  int getShortRangeRadius() const;
  int getLongRangeRadius() const;
  int getPickUpRangeRadius() const;
};