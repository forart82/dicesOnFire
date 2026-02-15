#include "Hub/AttackHub.h"

AttackHub::AttackHub(
    Hero &hero,
    Enemies &enemies) : m_hero(hero),
                        m_enemies(enemies)
{
}

AttackHub::~AttackHub() {}

void AttackHub::update(sf::Time &delta)
{
  checkRadars();
}

void AttackHub::checkRadars()
{
  for (const auto &enemy : m_enemies.getEnemies())
  {
    if (m_hero.insideShortRangeCircle(enemy->getBody().getShape().getPosition()))
    {
    }
    if (!enemy->getHoundHero() && enemy->insideWatchRangeCircle(m_hero.getBody().getShape().getPosition()))
    {
      enemy->houndHero();
    }
  }
}