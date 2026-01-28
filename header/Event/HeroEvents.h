#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Hero.h"
#include "_ENUMS.h"

class HeroEvents
{

private:
  Hero &m_hero;

public:
  HeroEvents(Hero &hero);
  ~HeroEvents();

  void keyPressed();
};