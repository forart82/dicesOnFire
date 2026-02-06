#include "Entity/EnemiesAttackService.h"

EnemiesAttackService ::EnemiesAttackService(
    Enemies &enemies,
    Hero &hero)
    : m_enemies(enemies),
      m_hero(hero)
{
}

EnemiesAttackService::~EnemiesAttackService() {}

void EnemiesAttackService::update(sf::Time &delta)
{
  checkRadars();
}

void EnemiesAttackService::checkRadars()
{
  for (const auto &enemy : m_enemies.getEnemies())
  {
    if (!enemy->getHoundHero() && enemy->insideWatchRangeCircle(m_hero.getBody().getShape().getPosition(), enemy->getWatchRangeCircle()))
    {
      enemy->houndHero();
    }
  }
}