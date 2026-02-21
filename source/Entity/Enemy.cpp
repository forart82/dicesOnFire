#include "Entity/Enemy.h"

Enemy::Enemy(Game &game)
    : BaseCharacterBody(game),
      m_game(game),
      m_hero(game.getHero()),
      m_floorItems(game.getFloorItems()),
      m_houndHero(false)
{
  for (int i = randomHelper::GET_RANDOM_NUMBER_INT(1, 1); i <= randomHelper::GET_RANDOM_NUMBER_INT(1, 2); i++)
  {
    m_dices.emplace_back(diceManager::CREATE_DICE(1));
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
    sf::Vector2f toPlayer = m_hero.getBody().getShape().getPosition() - m_bodyBox->getShape().getPosition();
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
  float left = m_bodyBox->getShape().getGlobalBounds().position.x;
  float top = m_bodyBox->getShape().getGlobalBounds().position.y;
  float width = m_bodyBox->getShape().getGlobalBounds().size.x;
  float height = m_bodyBox->getShape().getGlobalBounds().size.y;

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
  for (auto it = m_dices.begin(); it != m_dices.end();)
  {
    (*it)->resetLeftTop(m_leftTop);
    m_floorItems.addDice(std::move(*it));
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