#include "Entity/Circle.h"

Circle::Circle(Game &game)
    : m_isActive(true)
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

void Circle::addPosition(const sf::Vector2f &offset)
{
  sf::Vector2f newPosition = m_body.getPosition() + offset;
  m_body.setPosition(newPosition);
}

void Circle::toggleActive()
{
  m_isActive = !m_isActive;
}

void Circle::setShape(const Circle &body)
{
  m_body.setPosition(body.getShape().getPosition());
  m_body.setRadius(body.getShape().getRadius());
  m_body.setOutlineThickness(body.getShape().getOutlineThickness());
  m_body.setOrigin(sf::Vector2f(body.getShape().getRadius(), body.getShape().getRadius()));
  setColors(body.getShape().getFillColor(), body.getShape().getOutlineColor());
}

void Circle::setActive(bool isActive)
{
  m_isActive = isActive;
}

void Circle::setColors(const sf::Color &fillColor, const sf::Color &outlineColor)
{
  m_body.setFillColor(fillColor);
  m_body.setOutlineColor(outlineColor);
}

const sf::CircleShape &Circle::getShape() const
{
  return m_body;
}