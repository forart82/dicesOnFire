#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Enemies.h"
#include "Enemy.h"
#include "Entity/Hero.h"

class EnemyAttackService
{
private:
  Enemy &m_enemy;
  Hero &m_hero;

public:
  EnemyAttackService(
      Enemy &enemy,
      Hero &hero);

  ~EnemyAttackService();

  void update(sf::Time &delta);

  void checkRadars();
};