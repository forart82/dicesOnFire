#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Enemies.h"
#include "Entity/Hero.h"

class HeroAttackService
{
private:
  Hero &m_hero;
  Enemies &m_enemies;

public:
  HeroAttackService(
      Hero &hero,
      Enemies &enemies);

  ~HeroAttackService();

  void update(sf::Time &delta);

  void checkRadars();
};