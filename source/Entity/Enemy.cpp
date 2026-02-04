#include "Entity/Enemy.h"

Enemy::Enemy(
    Hero &hero,
    FloorItems &floorItmes)
    : Enemy(
          hero,
          floorItmes,
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

Enemy::Enemy(
    Hero &hero,
    FloorItems &floorItems,
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
      m_floorItems(floorItems),
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
                 longRangeRadius),
      VertexRectangle(
          0,
          0,
          800 + (ASSETS_TILE_SIZE * helper::GET_RANDOM_NUMBER_INT(0, 35)),
          2080 + (ASSETS_TILE_SIZE * helper::GET_RANDOM_NUMBER_INT(0, 1)))
{
  for (int i = helper::GET_RANDOM_NUMBER_INT(0, 1); i < helper::GET_RANDOM_NUMBER_INT(1, 3); i++)
  {
    m_dices.emplace_back(diceHelper::CREATE_DICE(1));
    std::cout << "dices: " << m_dices.size() << std::endl;
  }
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

void Enemy::removeHealth(int health)
{
  m_health -= health;
  if (m_health < 0)
  {
    m_health = 0;
  }
  float healthPercent = std::max(0.f, m_health / m_maxHealth);
  float maxWidth = m_healthBar->getOuter().getShape().getSize().x;
  m_healthBar->getInner().getShape().setSize({maxWidth * healthPercent, m_healthBar->getInner().getShape().getSize().y});
}

void Enemy::dropItemsOnFloor()
{
}

void Enemy::houndHero()
{
  m_houndHero = true;
}

bool &Enemy::getHoundHero()
{
  return m_houndHero;
}