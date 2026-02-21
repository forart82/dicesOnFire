#include "Entity/Circle.h"

Circle::Circle(Game &game)
    : m_game(game),
      m_isActive(true)
{
}

Circle::~Circle()
{
}

void Circle::update(sf::Time &delta)
{
}

void Circle::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if (m_isActive)
  {
    target.draw(m_body, states);
  }
}

void Circle::move(const sf::Vector2f &movement)
{
  m_body.move(movement);
}

void Circle::addPosition(const sf::Vector2f &offset)
{
  sf::Vector2f newPosition = m_body.getPosition() + offset;
  m_body.setPosition(newPosition);
}

void Circle::toggleActive()
{
  m_isActive = !m_isActive;
}

void Circle::setBody(const Circle &body)
{
  m_body.setPosition(body.getBody().getPosition());
  m_body.setRadius(body.getBody().getRadius());
  m_body.setOutlineThickness(body.getBody().getOutlineThickness());
  m_body.setOrigin(sf::Vector2f(body.getBody().getRadius(), body.getBody().getRadius()));
  setColors(body.getBody().getFillColor(), body.getBody().getOutlineColor());
}

void Circle::setPosition(const sf::Vector2f &position)
{
  m_body.setPosition(position);
}

void Circle::setRadius(int radius)
{
  m_body.setRadius(radius);
}

void Circle::setOrigin(const sf::Vector2f &origin)
{
  m_body.setOrigin(origin);
}

void Circle::setColors(const sf::Color &fillColor, const sf::Color &outlineColor)
{
  m_body.setFillColor(fillColor);
  m_body.setOutlineColor(outlineColor);
}

void Circle::setActive(bool isActive)
{
  m_isActive = isActive;
}

const sf::CircleShape &Circle::getBody() const
{
  return m_body;
}