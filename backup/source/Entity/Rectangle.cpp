#include "Entity/Rectangle.h"

Rectangle::Rectangle()
    : m_isActive(true)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::update(sf::Time &delta)
{
}

void Rectangle::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if (m_isActive)
  {
    target.draw(m_shape, states);
  }
}

void Rectangle::move(const sf::Vector2f &movement)
{
  m_shape.move(movement);
}

void Rectangle::addPosition(const sf::Vector2f &offset)
{
  sf::Vector2f newPosition = m_shape.getPosition() + offset;
  m_shape.setPosition(newPosition);
}

void Rectangle::toggleActive()
{
  m_isActive = !m_isActive;
}

void Rectangle::setRectangle(const Rectangle &rectangle)
{
  m_shape.setPosition(rectangle.getShape().getPosition());
  m_shape.setSize(rectangle.getShape().getSize());
  m_shape.setOutlineThickness(rectangle.getShape().getOutlineThickness());
  m_shape.setFillColor(rectangle.getShape().getFillColor());
  m_shape.setOutlineColor(rectangle.getShape().getOutlineColor());
  setOrigin();
}

void Rectangle::setPosition(const sf::Vector2f &position)
{
  m_shape.setPosition(position);
}

void Rectangle::setSize(const sf::Vector2f &size)
{
  m_shape.setSize(size);
  setOrigin();
}

void Rectangle::setOutlineThickness(int outlineThickness)
{
  m_shape.setOutlineThickness(outlineThickness);
}

void Rectangle::setColors(const sf::Color &fillColor, const sf::Color &outlineColor)
{
  m_shape.setFillColor(fillColor);
  m_shape.setOutlineColor(outlineColor);
}

void Rectangle::setOrigin()
{
  m_shape.setOrigin(
      sf::Vector2f(
          std::round(m_shape.getSize().x / 2.f),
          std::round(m_shape.getSize().y / 2.f)));
}

void Rectangle::setIsActive(bool isActive)
{
  m_isActive = isActive;
}

const sf::RectangleShape &Rectangle::getShape() const
{
  return m_shape;
}

bool Rectangle::getIsActive() const
{
  return m_isActive;
}