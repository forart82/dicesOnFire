#include "Entity/Hero.h"

Hero::Hero() {}

Hero::~Hero() {}

void Hero::update(sf::Time &delta)
{
  getDirectionAndMove(delta);
  m_direction = {};
}

void Hero::getDirectionAndMove(const sf::Time &delta)
{
  // Up Down
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
    m_direction.y = -1.f;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
    m_direction.y = 1.f;

  // Left Rigth
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
    m_direction.x = -1.f;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
    m_direction.x = 1.f;

  float length = std::sqrt(m_direction.x * m_direction.x + m_direction.y * m_direction.y);
  if (length > 0)
  {
    m_direction /= length;
  }
  BaseCharacterBody::move(m_direction, delta);
}