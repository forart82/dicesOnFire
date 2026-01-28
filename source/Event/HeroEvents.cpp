#include <SFML/Graphics.hpp>
#include "Event/HeroEvents.h"
#include "Entity/Hero.h"
#include "_ENUMS.h"

HeroEvents::HeroEvents(Hero &hero)
    : m_hero(hero) {};
HeroEvents::~HeroEvents() {};

void HeroEvents::input(sf::Keyboard::Scancode &code)
{
  switch (code)
  {
  case sf::Keyboard::Scancode::W:
  case sf::Keyboard::Scancode::Up:
    move(Direction::Up);
    break;
  case sf::Keyboard::Scancode::A:
  case sf::Keyboard::Scancode::Left:
    move(Direction::Left);
    break;
  case sf::Keyboard::Scancode::S:
  case sf::Keyboard::Scancode::Down:
    move(Direction::Down);
    break;
  case sf::Keyboard::Scancode::D:
  case sf::Keyboard::Scancode::Right:
    move(Direction::Right);
    break;
  default:
    break;
  }
}

void HeroEvents::move(Direction direction)
{
  if (direction == Direction::Up)
  {
    m_h
        direction.y -= 1.f;
  };
  if (direction == Direction::Left)
  {
    direction.y += 1.f;
  };
  if (direction == Direction::Down)
  {
    direction.x -= 1.f;
  };
  if (direction == Direction::Right)
  {
    direction.x += 1.f;
  };
}
