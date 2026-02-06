#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Enemies.h"
#include "Entity/Hero.h"

class EnemiesAttackService
{
private:
  Enemies &m_enemies;
  Hero &m_hero;

public:
  EnemiesAttackService(
      Enemies &enemies,
      Hero &hero);

  ~EnemiesAttackService();

  void update(sf::Time &delta);

  void checkRadars();
};