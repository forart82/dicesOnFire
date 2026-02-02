#include "Entity/BaseEntity.h"

BaseEntity::BaseEntity()
    : BaseEntity(
          std::make_unique<BaseRectangle>(),
          std::make_unique<BaseRectangleX2>(),
          std::make_unique<BaseCircle>(),
          std::make_unique<BaseCircle>(),
          std::make_unique<BaseCircle>(),
          100,
          100,
          2,
          300,
          25,
          50)
{
}

BaseEntity::BaseEntity(
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
    int longRangeRadius)
    : m_body(std::move(body)),
      m_healthBar(std::move(healthBar)),
      m_watchRangeCircle(std::move(watchRangeCircle)),
      m_shortRangeCircle(std::move(shortRangeCircle)),
      m_longRangeCircle(std::move(longRangeCircle)),
      m_health(health),
      m_maxHealth(maxHealth),
      m_speed(speed),
      m_watchRangeRadius(watchRangeRadius),
      m_shortRangeRadius(shortRangeRadius),
      m_longRangeRadius(longRangeRadius)
{
}

BaseEntity::~BaseEntity() {}

void BaseEntity::update(sf::Time &delta)
{
}

void BaseEntity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(*m_body);
  target.draw(*m_healthBar);
  target.draw(*m_watchRangeCircle);
  target.draw(*m_shortRangeCircle);
  target.draw(*m_longRangeCircle);
}

void BaseEntity::move(sf::Vector2f &movement)
{
  m_body->getShape().move({std::round(movement.x), std::round(movement.y)});
  m_healthBar->getOuter().getShape().move({std::round(movement.x), std::round(movement.y)});
  m_healthBar->getInner().getShape().move({std::round(movement.x), std::round(movement.y)});
  m_watchRangeCircle->getShape().move({std::round(movement.x), std::round(movement.y)});
  m_shortRangeCircle->getShape().move({std::round(movement.x), std::round(movement.y)});
  m_longRangeCircle->getShape().move({std::round(movement.x), std::round(movement.y)});
}

bool BaseEntity::insideWatchRangeCircle(const sf::Vector2f &targetPos, BaseCircle &radarPtr)
{
  return insideRadar(targetPos, radarPtr);
}

bool BaseEntity::insideShortRangeCircle(const sf::Vector2f &targetPos, BaseCircle &radarPtr)
{
  return insideRadar(targetPos, radarPtr);
}

bool BaseEntity::insideLongRangeCircle(const sf::Vector2f &targetPos, BaseCircle &radarPtr)
{
  return insideRadar(targetPos, radarPtr);
}

bool BaseEntity::insideRadar(const sf::Vector2f &targetPos, BaseCircle &radarPtr)
{

  float radius = radarPtr.getShape().getRadius();
  sf::Vector2f center = radarPtr.getShape().getPosition();

  float dx = targetPos.x - center.x;
  float dy = targetPos.y - center.y;

  return (dx * dx + dy * dy) <= (radius * radius);
}

void BaseEntity::setBody(std::unique_ptr<BaseRectangle> body)
{
  m_body = std::move(body);
}
void BaseEntity::setHealthBar(std::unique_ptr<BaseRectangleX2> healthBar)
{
  m_healthBar = std::move(healthBar);
}
void BaseEntity::setHealth(float health)
{
  m_health = health;
}
void BaseEntity::setMaxHealth(float maxHealth)
{
  m_maxHealth = maxHealth;
}
void BaseEntity::setSpeed(float speed)
{
  m_speed = speed;
}
void BaseEntity::setWatchRangeRadius(int watchRangeRadius)
{
  m_watchRangeRadius = watchRangeRadius;
}

BaseRectangle &BaseEntity::getBody()
{
  return *m_body;
}
BaseRectangleX2 &BaseEntity::getHealthBar()
{
  return *m_healthBar;
}
BaseCircle &BaseEntity::getWatchRangeCircle()
{
  return *m_watchRangeCircle;
}
BaseCircle &BaseEntity::getShortRangeCircle()
{
  return *m_shortRangeCircle;
}
BaseCircle &BaseEntity::getLongRangeCircle()
{
  return *m_longRangeCircle;
}
float &BaseEntity::getHealth()
{
  return m_health;
}
float &BaseEntity::getMaxHealth()
{
  return m_maxHealth;
}
float &BaseEntity::getSpeed()
{
  return m_speed;
}
int &BaseEntity::getWatchRangeRadius()
{
  return m_watchRangeRadius;
}
int &BaseEntity::getShortRangeRadius()
{
  return m_shortRangeRadius;
}
int &BaseEntity::getLongRangeRadius()
{
  return m_longRangeRadius;
}