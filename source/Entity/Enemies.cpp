#include "Entity/Enemies.h"

Enemies::Enemies()
    : m_game(game)
{
}

Enemies::~Enemies() {}

void Enemies::update(sf::Time &delta)
{
  removeEnemyOnDeath();
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

void Enemies::addEnemy(Hero &hero, FloorItems &floorItems)
{
  m_enemies.emplace_back(enemyManager::CREATE_ENEMY(hero, floorItems));
}

void Enemies::removeEnemyOnDeath()
{
  for (auto it = m_enemies.begin(); it != m_enemies.end();)
  {
    if ((*it)->getHealth() <= 0)
    {
      (*it)->dropItemsOnFloor();
      it = m_enemies.erase(it);
    }
    else
    {
      ++it;
    }
  }
}

const std::vector<std::unique_ptr<Enemy>> &Enemies::getEnemies() const
{
  return m_enemies;
}