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

void Rectangle::move(const sf::Vector2f &movement)
{
  m_body.move(movement);
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

void Rectangle::setBody(const Rectangle &rectangle)
{
  m_body.setPosition(rectangle.getBody().getPosition());
  m_body.setSize(rectangle.getBody().getSize());
  m_body.setOutlineThickness(rectangle.getBody().getOutlineThickness());
  m_body.setFillColor(rectangle.getBody().getFillColor());
  m_body.setOutlineColor(rectangle.getBody().getOutlineColor());
  setOriginFromSize(rectangle.getBody().getSize());
}

void Rectangle::setPosition(const sf::Vector2f &position)
{
  m_body.setPosition(position);
}

void Rectangle::setOriginFromSize(const sf::Vector2f &size)
{
  m_body.setOrigin({std::round(size.x / 2.f), std::round(size.y / 2.f)});
}

void Rectangle::setIsActive(bool isActive)
{
  m_isActive = isActive;
}

const sf::RectangleShape &Rectangle::getBody() const
{
  return m_body;
}

bool Rectangle::getIsActive() const
{
  return m_isActive;
}