#include "Entity/Enemy.h"

Enemy::Enemy()
    : m_houndHero(false)
{
  for (int i = randomHelper::GET_RANDOM_NUMBER_INT(1, 1); i <= randomHelper::GET_RANDOM_NUMBER_INT(1, 2); i++)
  {
    m_dices.emplace_back(m_game->getDiceManager().createDice(1));
  }
}

Enemy::~Enemy() {}

void Enemy::update(sf::Time &delta)
{
  move(delta);
  prepareVertex();
}

void Enemy::move(const sf::Time &delta)
{
  if (m_houndHero)
  {
    sf::Vector2f direction;
    sf::Vector2f toPlayer = m_game->getHero().getBody().getShape().getPosition() - m_body->getShape().getPosition();
    float distance = std::sqrt(toPlayer.x * toPlayer.x + toPlayer.y * toPlayer.y);
    if (distance != 0) // Éviter la division par zéro
    {
      direction = toPlayer / distance;
    }
    sf::Vector2f movement = direction * m_speed * delta.asSeconds();
    BaseCharacterBody::move(movement);
  }
}

void Enemy::prepareVertex()
{
  float left = m_body->getShape().getGlobalBounds().position.x;
  float top = m_body->getShape().getGlobalBounds().position.y;
  float width = m_body->getShape().getGlobalBounds().size.x;
  float height = m_body->getShape().getGlobalBounds().size.y;

  setVertexAssetBodyFloatRect(
      sf::FloatRect(
          sf::Vector2f(left, top),
          sf::Vector2f(width, height)));
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
  m_healthBar->setInnerSize(
      sf::Vector2f(maxWidth * healthPercent, m_healthBar->getInner().getShape().getSize().y));
}

void Enemy::dropItemsOnFloor()
{
  for (auto it = m_dices.begin(); it != m_dices.end();)
  {
    (*it)->makeAll();
    m_game->getFloorItems().addDice(std::move(*it));
    it = m_dices.erase(it);
  }
}

void Enemy::houndHero()
{
  m_houndHero = true;
}

bool Enemy::getHoundHero() const
{
  return m_houndHero;
}