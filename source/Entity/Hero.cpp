#include "Entity/Hero.h"

Hero::Hero()
    : Hero(std::make_unique<Rectangle>(),
           std::make_unique<RectangleX2>(),
           std::make_unique<Circle>(),
           std::make_unique<Circle>(),
           std::make_unique<Circle>(),
           100,
           100,
           2,
           300,
           25,
           50)
{
}

Hero::Hero(
    std::unique_ptr<Rectangle> bodyBox,
    std::unique_ptr<RectangleX2> healthBar,
    std::unique_ptr<Circle> watchRangeCircle,
    std::unique_ptr<Circle> shortRangeCircle,
    std::unique_ptr<Circle> longRangeCircle,
    float health,
    float maxHealth,
    float speed,
    int watchRangeRadius,
    int shortRangeRadius,
    int longRangeRadius)
    : CharacterBody(
          std::move(bodyBox),
          std::move(healthBar),
          std::move(watchRangeCircle),
          std::move(shortRangeCircle),
          std::move(longRangeCircle),
          health,
          maxHealth,
          speed,
          watchRangeRadius,
          shortRangeRadius,
          longRangeRadius)
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
  CharacterBody::move(movement);
}