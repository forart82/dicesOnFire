#include "Entity/BaseCharacterBody.h"

BaseCharacterBody::BaseCharacterBody(
    Game &game)
    : VertexRectangleDrawable(game),
      m_game(game)
{
}

BaseCharacterBody::~BaseCharacterBody() {}

void BaseCharacterBody::update(sf::Time &delta)
{
}

void BaseCharacterBody::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if (m_debugIsActive)
  {
    target.draw(*m_bodyBox);
  }
  target.draw(*m_watchRangeCircle);
  target.draw(*m_shortRangeCircle);
  target.draw(*m_longRangeCircle);
  target.draw(*m_pickUpRangeCircle);
  target.draw(*m_healthBar);
}

void BaseCharacterBody::move(sf::Vector2f &movement)
{
  m_bodyBox->getShape().move({std::round(movement.x), std::round(movement.y)});
  m_healthBar->getOuter().getShape().move({std::round(movement.x), std::round(movement.y)});
  m_healthBar->getInner().getShape().move({std::round(movement.x), std::round(movement.y)});
  m_watchRangeCircle->getShape().move({std::round(movement.x), std::round(movement.y)});
  m_shortRangeCircle->getShape().move({std::round(movement.x), std::round(movement.y)});
  m_longRangeCircle->getShape().move({std::round(movement.x), std::round(movement.y)});
  m_pickUpRangeCircle->getShape().move({std::round(movement.x), std::round(movement.y)});
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

void BaseCharacterBody::setBody(std::unique_ptr<Rectangle> bodyBox)
{
  m_bodyBox = std::move(bodyBox);
}
void BaseCharacterBody::setHealthBar(std::unique_ptr<RectangleX2> healthBar)
{
  m_healthBar = std::move(healthBar);
}
void BaseCharacterBody::setHealth(float health)
{
  m_health = health;
}
void BaseCharacterBody::setMaxHealth(float maxHealth)
{
  m_maxHealth = maxHealth;
}
void BaseCharacterBody::setSpeed(float speed)
{
  m_speed = speed;
}
void BaseCharacterBody::setWatchRangeRadius(int watchRangeRadius)
{
  m_watchRangeRadius = watchRangeRadius;
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
  return *m_bodyBox;
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
float &BaseCharacterBody::getHealth() const
{
  return m_health;
}
float &BaseCharacterBody::getMaxHealth() const
{
  return m_maxHealth;
}
float &BaseCharacterBody::getSpeed() const
{
  return m_speed;
}
int &BaseCharacterBody::getWatchRangeRadius() const
{
  return m_watchRangeRadius;
}
int &BaseCharacterBody::getShortRangeRadius() const
{
  return m_shortRangeRadius;
}
int &BaseCharacterBody::getLongRangeRadius() const
{
  return m_longRangeRadius;
}
int &BaseCharacterBody::getPickUpRangeRadius() const
{
  return m_pickUpRangeRadius;
}