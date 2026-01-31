#include "Entity/Enemy.h"

Enemy::Enemy(Hero &hero)
    : Enemy(hero,
            std::make_unique<BaseRectangle>(),
            std::make_unique<BaseRectangleX2>(),
            std::make_unique<BaseCircle>(),
            std::make_unique<BaseCircle>(),
            2500,
            100,
            200,
            25,
            25,
            50)
{
}

Enemy::Enemy(Hero &hero,
             std::unique_ptr<BaseRectangle> body,
             std::unique_ptr<BaseRectangleX2> healthBar,
             std::unique_ptr<BaseCircle> shortRangeCircle,
             std::unique_ptr<BaseCircle> longRangeCircle,
             float health,
             float maxHealth,
             float speed,
             int watchRangeRadius,
             int shortRangeRadius,
             int longRangeRadius)
    : m_hero(hero),
      BaseEntity(std::move(body),
                 std::move(healthBar),
                 std::move(shortRangeCircle),
                 std::move(longRangeCircle),
                 health,
                 maxHealth,
                 speed,
                 watchRangeRadius,
                 shortRangeRadius,
                 longRangeRadius) {}

Enemy::~Enemy() {}

void Enemy::update(sf::Time &delta)
{
  move(delta);
}

void Enemy::move(sf::Time &delta)
{
  sf::Vector2f direction;
  sf::Vector2f toPlayer = m_hero.getBody().getShape().getPosition() - m_body->getShape().getPosition();
  float distance = std::sqrt(toPlayer.x * toPlayer.x + toPlayer.y * toPlayer.y);
  if (distance != 0) // Éviter la division par zéro
  {
    direction = toPlayer / distance;
  }
  sf::Vector2f movement = direction * m_speed * delta.asSeconds();
  m_body->getShape().move(movement);
}