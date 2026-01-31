#include "Entity/BaseEntity.h"

BaseEntity::BaseEntity()
    : BaseEntity(
          std::make_unique<BaseRectangle>(),
          std::make_unique<BaseRectangleX2>(),
          100,
          100,
          2,
          25)
{
}

BaseEntity::BaseEntity(
    std::unique_ptr<BaseRectangle> body,
    std::unique_ptr<BaseRectangleX2> healthBar,
    float health,
    float maxHealth,
    float speed,
    int watchRadius)
    : m_health(health),
      m_maxHealth(maxHealth),
      m_speed(speed),
      m_watchRadius(watchRadius)
{
  m_body = std::move(body);
  m_healthBar = std::move(healthBar);
}

BaseEntity::~BaseEntity() {}

void BaseEntity::update(sf::Time &delta)
{
}

void BaseEntity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(*m_body);
  target.draw(*m_healthBar);
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
void BaseEntity::setWatchRadius(int watchRadius)
{
  m_watchRadius = watchRadius;
}

BaseRectangle &BaseEntity::getBody()
{
  return *m_body;
}
BaseRectangleX2 &BaseEntity::getHealthBar()
{
  return *m_healthBar;
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
int &BaseEntity::getWatchRadius()
{
  return m_watchRadius;
}