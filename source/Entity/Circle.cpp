#include "Entity/Circle.h"

Circle::Circle()
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
    target.draw(m_shape, states);
  }
}

void Circle::move(const sf::Vector2f &movement)
{
  m_shape.move(movement);
}

void Circle::addPosition(const sf::Vector2f &offset)
{
  sf::Vector2f newPosition = m_shape.getPosition() + offset;
  m_shape.setPosition(newPosition);
}

void Circle::toggleActive()
{
  m_isActive = !m_isActive;
}

void Circle::setCircle(const Circle &circle)
{
  m_shape.setPosition(circle.getShape().getPosition());
  m_shape.setRadius(circle.getShape().getRadius());
  m_shape.setOutlineThickness(circle.getShape().getOutlineThickness());
  setOrigin();
  setColors(circle.getShape().getFillColor(), circle.getShape().getOutlineColor());
}

void Circle::setPosition(const sf::Vector2f &position)
{
  m_shape.setPosition(position);
}

void Circle::setRadius(int radius)
{
  m_shape.setRadius(radius);
  setOrigin();
}

void Circle::setOutlineThickness(int outlineThickness)
{
  m_shape.setOutlineThickness(outlineThickness);
}

void Circle::setOrigin()
{
  m_shape.setOrigin(
      sf::Vector2f(
          std::round(m_shape.getRadius()),
          std::round(m_shape.getRadius())));
}

void Circle::setColors(const sf::Color &fillColor, const sf::Color &outlineColor)
{
  m_shape.setFillColor(fillColor);
  m_shape.setOutlineColor(outlineColor);
}

void Circle::setIsActive(bool isActive)
{
  m_isActive = isActive;
}

const sf::CircleShape &Circle::getShape() const
{
  return m_shape;
}