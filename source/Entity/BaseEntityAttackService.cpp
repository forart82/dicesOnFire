#include "Entity/BaseEntityAttackService.h"

BaseEntityAttackService::BaseEntityAttackService(
    Hero &hero,
    Enemies &enemies) : m_hero(hero),
                        m_enemies(enemies)
{
}

BaseEntityAttackService::~BaseEntityAttackService() {}

void BaseEntityAttackService::update(sf::Time &delta)
{
  checkRadars();
}

void BaseEntityAttackService::checkRadars()
{
  for (const auto &enemy : m_enemies.getEnemies())
  {
    if (m_hero.insideShortRangeCircle(enemy->getBody().getShape().getPosition(), m_hero.getShortRangeCircle()))
    {
    }
  }
}