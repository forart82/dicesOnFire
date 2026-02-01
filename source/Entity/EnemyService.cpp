#include "Entity/EnemyService.h"

EnemyService :: EnemyService (
    Hero &hero) : m_hero(hero)
{
}

EnemyService :: EnemyService {}

void EnemyService::update(sf::Time &delta)
{
  checkRadars();
}

void EnemyService::checkRadars()
{
    if (m_hero.insideShortRangeCircle(enemy->getBody().getShape().getPosition(), m_hero.getShortRangeCircle()))
    {
    }
  
}