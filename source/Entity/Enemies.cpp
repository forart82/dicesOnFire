#include "Entity/Enemies.h"

Enemies::Enemies() {}

Enemies::~Enemies() {}

void Enemies::update(sf::Time &delta)
{

  for (auto &enemy : m_enemies)
  {
    enemy->update(delta);
  }
}

void Enemies::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  for (auto &enemy : m_enemies)
  {
    target.draw(*enemy, states);
  }
}

void Enemies::addEnemy(Hero &hero)
{
  m_enemies.emplace_back(enemyHelper::CREATE_ENEMY(hero));
}

void Enemies::removeEnemyOnDeath()
{
  m_enemies.erase(
      std::remove_if(
          m_enemies.begin(),
          m_enemies.end(),
          [](const auto &enemy)
          {
            return enemy->getHealth() <= 0;
          }),
      m_enemies.end());
}

const std::vector<std::unique_ptr<Enemy>> &Enemies::getEnemies() const
{
  return m_enemies;
}