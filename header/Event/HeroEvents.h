#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Hero.h"

class HeroEvents
{

private:
  Hero &m_hero;

public:
  HeroEvents(Hero &hero);
  ~HeroEvents();

  void handleCodes(sf::Keyboard::Scancode &code);
};