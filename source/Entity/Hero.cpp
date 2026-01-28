#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity/BaseEntity.h"
#include "Entity/Hero.h"
#include "Form/BaseRectangle.h"
#include "Form/BaseRectangleX2.h"
#include "_ENUMS.h"

Hero::Hero()
    : Hero(std::make_unique<BaseRectangle>(),
           std::make_unique<BaseRectangleX2>(),
           100,
           100,
           2)
{
}

Hero::Hero(
    std::unique_ptr<BaseRectangle> body,
    std::unique_ptr<BaseRectangleX2> healthBar,
    float health,
    float maxHealth,
    float speed)
    : BaseEntity(
          std::move(body),
          std::move(healthBar),
          health,
          maxHealth,
          speed)
{
}

Hero::~Hero() {}

void Hero::update(sf::Time &delta)
{
  move(delta);
  m_direction = {};
}

void Hero::move(sf::Time &delta)
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
  sf::Vector2f movement = m_direction * m_speed * delta.asSeconds();
  m_body->getShape().move({std::round(movement.x), std::round(movement.y)});
  m_healthBar->getOuter().getShape().move({std::round(movement.x), std::round(movement.y)});
  m_healthBar->getInner().getShape().move({std::round(movement.x), std::round(movement.y)});
}
