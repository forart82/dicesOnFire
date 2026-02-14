#include "Entity/CharacterBody.h"

CharacterBody::CharacterBody()
    : CharacterBody(
          std::make_unique<Rectangle>(),
          std::make_unique<RectangleX2>(),
          std::make_unique<Circle>(),
          std::make_unique<Circle>(),
          std::make_unique<Circle>(),
          100,
          100,
          2,
          300,
          25,
          50)
{
}

CharacterBody::CharacterBody(
    std::unique_ptr<Rectangle> bodyBox,
    std::unique_ptr<RectangleX2> healthBar,
    std::unique_ptr<Circle> watchRangeCircle,
    std::unique_ptr<Circle> shortRangeCircle,
    std::unique_ptr<Circle> longRangeCircle,
    float health,
    float maxHealth,
    float speed,
    int watchRangeRadius,
    int shortRangeRadius,
    int longRangeRadius)
    : m_bodyBox(std::move(bodyBox)),
      m_healthBar(std::move(healthBar)),
      m_watchRangeCircle(std::move(watchRangeCircle)),
      m_shortRangeCircle(std::move(shortRangeCircle)),
      m_longRangeCircle(std::move(longRangeCircle)),
      m_health(health),
      m_maxHealth(maxHealth),
      m_speed(speed),
      m_watchRangeRadius(watchRangeRadius),
      m_shortRangeRadius(shortRangeRadius),
      m_longRangeRadius(longRangeRadius),
      m_debugIsActive(false)
{
}

CharacterBody::~CharacterBody() {}

void CharacterBody::update(sf::Time &delta)
{
}

void CharacterBody::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if (m_debugIsActive)
  {
    target.draw(*m_bodyBox);
  }
  target.draw(*m_watchRangeCircle);
  target.draw(*m_shortRangeCircle);
  target.draw(*m_longRangeCircle);
  target.draw(*m_healthBar);
}

void CharacterBody::move(sf::Vector2f &movement)
{
  m_bodyBox->getShape().move({std::round(movement.x), std::round(movement.y)});
  m_healthBar->getOuter().getShape().move({std::round(movement.x), std::round(movement.y)});
  m_healthBar->getInner().getShape().move({std::round(movement.x), std::round(movement.y)});
  m_watchRangeCircle->getShape().move({std::round(movement.x), std::round(movement.y)});
  m_shortRangeCircle->getShape().move({std::round(movement.x), std::round(movement.y)});
  m_longRangeCircle->getShape().move({std::round(movement.x), std::round(movement.y)});
}

bool CharacterBody::insideWatchRangeCircle(const sf::Vector2f &targetPos, Circle &radarPtr)
{
  return collisionHelper::insideRadar(targetPos, radarPtr);
}

bool CharacterBody::insideShortRangeCircle(const sf::Vector2f &targetPos, Circle &radarPtr)
{
  return collisionHelper::insideRadar(targetPos, radarPtr);
}

bool CharacterBody::insideLongRangeCircle(const sf::Vector2f &targetPos, Circle &radarPtr)
{
  return collisionHelper::insideRadar(targetPos, radarPtr);
}

void CharacterBody::setBody(std::unique_ptr<Rectangle> bodyBox)
{
  m_bodyBox = std::move(bodyBox);
}
void CharacterBody::setHealthBar(std::unique_ptr<RectangleX2> healthBar)
{
  m_healthBar = std::move(healthBar);
}
void CharacterBody::setHealth(float health)
{
  m_health = health;
}
void CharacterBody::setMaxHealth(float maxHealth)
{
  m_maxHealth = maxHealth;
}
void CharacterBody::setSpeed(float speed)
{
  m_speed = speed;
}
void CharacterBody::setWatchRangeRadius(int watchRangeRadius)
{
  m_watchRangeRadius = watchRangeRadius;
}

void CharacterBody::toggleDebugIsActive()
{
  m_debugIsActive = !m_debugIsActive;
}

Rectangle &CharacterBody::getBody()
{
  return *m_bodyBox;
}
RectangleX2 &CharacterBody::getHealthBar()
{
  return *m_healthBar;
}
Circle &CharacterBody::getWatchRangeCircle()
{
  return *m_watchRangeCircle;
}
Circle &CharacterBody::getShortRangeCircle()
{
  return *m_shortRangeCircle;
}
Circle &CharacterBody::getLongRangeCircle()
{
  return *m_longRangeCircle;
}
float &CharacterBody::getHealth()
{
  return m_health;
}
float &CharacterBody::getMaxHealth()
{
  return m_maxHealth;
}
float &CharacterBody::getSpeed()
{
  return m_speed;
}
int &CharacterBody::getWatchRangeRadius()
{
  return m_watchRangeRadius;
}
int &CharacterBody::getShortRangeRadius()
{
  return m_shortRangeRadius;
}
int &CharacterBody::getLongRangeRadius()
{
  return m_longRangeRadius;
}