#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Entity/Circle.h"
#include "Entity/Rectangle.h"
#include "Entity/RectangleX2.h"

class Moveable
{
private:
  Rectangle *m_movableBody = nullptr;
  RectangleX2 *m_movableHealthBar = nullptr;
  Circle *m_moveableWatchRangeCircle = nullptr;
  Circle *m_moveableShortRangeCircle = nullptr;
  Circle *m_moveableLongRangeCircle = nullptr;
  Circle *m_moveablePickUpRangeCircle = nullptr;

protected:
  float m_speed;

public:
  Moveable() = default;
  virtual ~Moveable() = default;

  void bind(
      Rectangle *m_movableBody,
      RectangleX2 *m_movableHealthBar,
      Circle *m_watchRangeCircle,
      Circle *m_shortRangeCircle,
      Circle *m_longRangeCircle,
      Circle *m_pickUpRangeCircle);

  void move(const sf::Vector2f &direction, const sf::Time &delta);

  void setSpeed(float speed);

  const float getSpeed() const;
};