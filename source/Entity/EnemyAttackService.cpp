#include "Entity/EnemyAttackService.h"

EnemyAttackService ::EnemyAttackService(
    Enemy &enemy,
    Hero &hero)
    : m_enemy(enemy),
      m_hero(hero)
{
}

EnemyAttackService::~EnemyAttackService() {}

void EnemyAttackService::update(sf::Time &delta)
{
  checkRadars();
}

void EnemyAttackService::checkRadars()
{
  if (!m_enemy.getHoundHero() && m_enemy.insideWatchRangeCircle(m_hero.getBody().getShape().getPosition(), m_enemy.getWatchRangeCircle()))
  {
    m_enemy.houndHero();
  }
}