#include "Ability/Moveable.h"

void Moveable::bind(
    Rectangle *body,
    RectangleX2 *healthBar,
    Circle *watchRangeCircle,
    Circle *shortRangeCircle,
    Circle *longRangeCircle,
    Circle *pickUpRangeCircle)
{
  m_movableBody = body;
  m_movableHealthBar = healthBar;
  m_moveableWatchRangeCircle = watchRangeCircle;
  m_moveableShortRangeCircle = shortRangeCircle;
  m_moveableLongRangeCircle = longRangeCircle;
  m_moveablePickUpRangeCircle = pickUpRangeCircle;
}

void Moveable::move(const sf::Vector2f &direction, const sf::Time &delta)
{
  auto movement = direction * m_speed * delta.asSeconds();
  m_movableBody->move(sf::Vector2f(std::round(movement.x), std::round(movement.y)));
  m_movableHealthBar->move(sf::Vector2f(std::round(movement.x), std::round(movement.y)));
  m_moveableWatchRangeCircle->move(sf::Vector2f(std::round(movement.x), std::round(movement.y)));
  m_moveableShortRangeCircle->move(sf::Vector2f(std::round(movement.x), std::round(movement.y)));
  m_moveableLongRangeCircle->move(sf::Vector2f(std::round(movement.x), std::round(movement.y)));
  m_moveablePickUpRangeCircle->move(sf::Vector2f(std::round(movement.x), std::round(movement.y)));
}

void Moveable::setSpeed(float speed)
{
  m_speed = speed;
}

const float Moveable::getSpeed() const
{
  return m_speed;
}