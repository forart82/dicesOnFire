#include "Entity/Rectangle.h"

Rectangle::Rectangle(Game &game)
    : m_game(game),
      m_isActive(true)
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
    target.draw(m_body, states);
  }
}

void Rectangle::addPosition(const sf::Vector2f &offset)
{
  sf::Vector2f newPosition = m_body.getPosition() + offset;
  m_body.setPosition(newPosition);
}

void Rectangle::toggleActive()
{
  m_isActive = !m_isActive;
}

void Rectangle::setBody(const Rectangle &baseRectangle)
{
  m_body.setPosition(baseRectangle.m_body.getPosition());
  m_body.setSize(baseRectangle.m_body.getSize());
  m_body.setOutlineThickness(baseRectangle.getShape().getOutlineThickness());
  m_body.setFillColor(baseRectangle.m_body.getFillColor());
  m_body.setOutlineColor(baseRectangle.m_body.getOutlineColor());
  setOriginFromSize(baseRectangle.m_body.getSize());
}

void Rectangle::setOriginFromSize(const sf::Vector2f &size)
{
  m_body.setOrigin({std::round(size.x / 2.f), std::round(size.y / 2.f)});
}

void Rectangle::setIsActive(bool isActive)
{
  m_isActive = isActive;
}

const sf::RectangleShape &Rectangle::getShape() const
{
  return m_body;
}

bool Rectangle::getIsActive() const
{
  return m_isActive;
}