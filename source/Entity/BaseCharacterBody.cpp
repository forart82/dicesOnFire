#include "Entity/BaseCharacterBody.h"

BaseCharacterBody::BaseCharacterBody()
{
  Damageable::bind(
      m_body.get(),
      m_healthBar.get());

  Moveable::bind(
      m_body.get(),
      m_healthBar.get(),
      m_watchRangeCircle.get(),
      m_shortRangeCircle.get(),
      m_longRangeCircle.get(),
      m_pickUpRangeCircle.get());
}

void BaseCharacterBody::update(sf::Time &delta)
{
}

void BaseCharacterBody::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if (m_debugIsActive)
  {
    target.draw(*m_body);
  }
  target.draw(*m_watchRangeCircle);
  target.draw(*m_shortRangeCircle);
  target.draw(*m_longRangeCircle);
  target.draw(*m_pickUpRangeCircle);
  target.draw(*m_healthBar);
}

bool BaseCharacterBody::insideWatchRangeCircle(const sf::Vector2f &targetPos) const
{
  return collisionHelper::insideRadar(targetPos, *m_watchRangeCircle);
}

bool BaseCharacterBody::insideShortRangeCircle(const sf::Vector2f &targetPos) const
{
  return collisionHelper::insideRadar(targetPos, *m_shortRangeCircle);
}

bool BaseCharacterBody::insideLongRangeCircle(const sf::Vector2f &targetPos) const
{
  return collisionHelper::insideRadar(targetPos, *m_longRangeCircle);
}

bool BaseCharacterBody::insidePickUpRangeCircle(const sf::Vector2f &targetPos) const
{
  return collisionHelper::insideRadar(targetPos, *m_pickUpRangeCircle);
}

void BaseCharacterBody::setBody(std::unique_ptr<Rectangle> body)
{
  m_body = std::move(body);
}
void BaseCharacterBody::setHealthBar(std::unique_ptr<RectangleX2> healthBar)
{
  m_healthBar = std::move(healthBar);
}

void BaseCharacterBody::setWatchRangeCircle(std::unique_ptr<Circle> watchRangeCircle)
{
  m_watchRangeCircle = std::move(watchRangeCircle);
}
void BaseCharacterBody::setShortRangeCircle(std::unique_ptr<Circle> shortRangeCircle)
{
  m_shortRangeCircle = std::move(shortRangeCircle);
}
void BaseCharacterBody::setLongRangeCircle(std::unique_ptr<Circle> longRangeCircle)
{
  m_longRangeCircle = std::move(longRangeCircle);
}
void BaseCharacterBody::setPickUpRangeCircle(std::unique_ptr<Circle> pickUpRangeCircle)
{
  m_pickUpRangeCircle = std::move(pickUpRangeCircle);
}

void BaseCharacterBody::setWatchRangeRadius(int watchRangeRadius)
{
  m_watchRangeRadius = watchRangeRadius;
}
void BaseCharacterBody::setShortRangeRadius(int shortRangeRadius)
{
  m_shortRangeRadius = shortRangeRadius;
}
void BaseCharacterBody::setLongRangeRadius(int longRangeRadius)
{
  m_longRangeRadius = longRangeRadius;
}
void BaseCharacterBody::setPickUpRangeRadius(int pickUpRangeRadius)
{
  m_pickUpRangeRadius = pickUpRangeRadius;
}

void BaseCharacterBody::toggleDebugIsActive()
{
  m_debugIsActive = !m_debugIsActive;
}

const Rectangle &BaseCharacterBody::getBody() const
{
  return *m_body;
}
const RectangleX2 &BaseCharacterBody::getHealthBar() const
{
  return *m_healthBar;
}
const Circle &BaseCharacterBody::getWatchRangeCircle() const
{
  return *m_watchRangeCircle;
}
const Circle &BaseCharacterBody::getShortRangeCircle() const
{
  return *m_shortRangeCircle;
}
const Circle &BaseCharacterBody::getLongRangeCircle() const
{
  return *m_longRangeCircle;
}
const Circle &BaseCharacterBody::getPickUpRangeCircle() const
{
  return *m_pickUpRangeCircle;
}

int BaseCharacterBody::getWatchRangeRadius() const
{
  return m_watchRangeRadius;
}
int BaseCharacterBody::getShortRangeRadius() const
{
  return m_shortRangeRadius;
}
int BaseCharacterBody::getLongRangeRadius() const
{
  return m_longRangeRadius;
}
int BaseCharacterBody::getPickUpRangeRadius() const
{
  return m_pickUpRangeRadius;
}