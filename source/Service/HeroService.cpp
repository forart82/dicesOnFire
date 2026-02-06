#include "Entity/HeroAttackService.h"

HeroAttackService::HeroAttackService(
    Hero &hero,
    Enemies &enemies) : m_hero(hero),
                        m_enemies(enemies)
{
}

HeroAttackService::~HeroAttackService() {}

void HeroAttackService::update(sf::Time &delta)
{
  checkRadars();
}

void HeroAttackService::checkRadars()
{
  for (const auto &enemy : m_enemies.getEnemies())
  {
    if (m_hero.insideShortRangeCircle(enemy->getBody().getShape().getPosition(), m_hero.getShortRangeCircle()))
    {
    }
  }
}