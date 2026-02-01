#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Enemies.h"
#include "Entity/Hero.h"

class EnemyService
{
private:
  Hero &m_hero;

public:
  EnemyService(
      Hero &hero);

  ~EnemyService();

  void update(sf::Time &delta);

  void checkRadars();
};