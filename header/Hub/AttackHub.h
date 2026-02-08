#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Enemies.h"
#include "Entity/Hero.h"

class AttackHub
{
private:
  Hero &m_hero;
  Enemies &m_enemies;

public:
  AttackHub(
      Hero &hero,
      Enemies &enemies);

  ~AttackHub();

  void update(sf::Time &delta);

  void checkRadars();
};