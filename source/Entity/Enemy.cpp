#include "Entity/Enemy.h"

Enemy::Enemy(Hero &hero)
    : Enemy(hero,
            std::make_unique<BaseRectangle>(),
            std::make_unique<BaseRectangleX2>(),
            std::make_unique<BaseCircle>(),
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
             std::unique_ptr<BaseCircle> watchRangeCircle,
             std::unique_ptr<BaseCircle> shortRangeCircle,
             std::unique_ptr<BaseCircle> longRangeCircle,
             float health,
             float maxHealth,
             float speed,
             int watchRangeRadius,
             int shortRangeRadius,
             int longRangeRadius)
    : m_hero(hero),
      m_houndHero(false),
      BaseEntity(std::move(body),
                 std::move(healthBar),
                 std::move(watchRangeCircle),
                 std::move(shortRangeCircle),
                 std::move(longRangeCircle),
                 health,
                 maxHealth,
                 speed,
                 watchRangeRadius,
                 shortRangeRadius,
                 longRangeRadius)
{
  m_assetsLeft = 800 + (ASSETS_TILE_SIZE * helper::GET_RANDOM_NUMBER_INT(0, 35));
  m_assetsTop = 2080 + (ASSETS_TILE_SIZE * helper::GET_RANDOM_NUMBER_INT(0, 1));
  m_assetsLeftTop = sf::Vector2f(m_assetsLeft, m_assetsTop);
  m_assetsRightTop = sf::Vector2f(m_assetsLeft + ASSETS_TILE_SIZE, m_assetsTop);
  m_assetsLeftBottom = sf::Vector2f(m_assetsLeft, m_assetsTop + ASSETS_TILE_SIZE);
  m_assetsRightBottom = sf::Vector2f(m_assetsLeft + ASSETS_TILE_SIZE, m_assetsTop + ASSETS_TILE_SIZE);
}

Enemy::~Enemy() {}

void Enemy::update(sf::Time &delta)
{
  move(delta);
  prepareVertex();
}

void Enemy::move(sf::Time &delta)
{
  if (m_houndHero)
  {
    sf::Vector2f direction;
    sf::Vector2f toPlayer = m_hero.getBody().getShape().getPosition() - m_body->getShape().getPosition();
    float distance = std::sqrt(toPlayer.x * toPlayer.x + toPlayer.y * toPlayer.y);
    if (distance != 0) // Éviter la division par zéro
    {
      direction = toPlayer / distance;
    }
    sf::Vector2f movement = direction * m_speed * delta.asSeconds();
    BaseEntity::move(movement);
  }
}

void Enemy::prepareVertex()
{
  float left = m_body->getShape().getGlobalBounds().position.x;
  float top = m_body->getShape().getGlobalBounds().position.y;
  float width = m_body->getShape().getGlobalBounds().size.x;
  float height = m_body->getShape().getGlobalBounds().size.y;

  m_leftTop = sf::Vector2f(left, top);
  m_rightTop = sf::Vector2f(left + width, top);
  m_leftBottom = sf::Vector2f(left, top + height);
  m_rightBottom = sf::Vector2f(left + width, top + height);
}

void Enemy::houndHero()
{
  m_houndHero = true;
}

bool &Enemy::getHoundHero()
{
  return m_houndHero;
}

sf::Vector2f &Enemy::getLeftTop()
{
  return m_leftTop;
}

sf::Vector2f &Enemy::getRightTop()
{
  return m_rightTop;
}

sf::Vector2f &Enemy::getLeftBottom()
{
  return m_leftBottom;
}

sf::Vector2f &Enemy::getRightBottom()
{
  return m_rightBottom;
}

sf::Vector2f &Enemy::getAssetsLeftTop()
{
  return m_assetsLeftTop;
}

sf::Vector2f &Enemy::getAssetsRightTop()
{
  return m_assetsRightTop;
}

sf::Vector2f &Enemy::getAssetsLeftBottom()
{
  return m_assetsLeftBottom;
}

sf::Vector2f &Enemy::getAssetsRightBottom()
{
  return m_assetsRightBottom;
}
