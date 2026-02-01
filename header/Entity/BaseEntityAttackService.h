#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Enemies.h"
#include "Entity/Hero.h"

class BaseEntityAttackService
{
private:
  Hero &m_hero;
  Enemies &m_enemies;

public:
  BaseEntityAttackService(
      Hero &hero,
      Enemies &enemies);

  ~BaseEntityAttackService();

  void update(sf::Time &delta);

  void checkRadars();
};