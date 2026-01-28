#include <SFML/Graphics.hpp>
#include "Event/HeroEvents.h"
#include "Entity/Hero.h"

HeroEvents::HeroEvents(Hero &hero)
    : m_hero(hero) {};
HeroEvents::~HeroEvents() {};

void HeroEvents::input(sf::Keyboard::Scancode &code)
{
  switch (code)
  {
  case sf::Keyboard::Scancode::W:
  case sf::Keyboard::Scancode::A:
  case sf::Keyboard::Scancode::S:
  case sf::Keyboard::Scancode::D:
  case sf::Keyboard::Scancode::Up:
  case sf::Keyboard::Scancode::Left:
  case sf::Keyboard::Scancode::Down:
  case sf::Keyboard::Scancode::Right:

    break;
  default:
    break;
  }
}

void move(sf::Keyboard::Scancode &code)
