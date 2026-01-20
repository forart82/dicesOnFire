#include <SFML/Graphics.hpp>
#include "../header/_BaseRectangle.h"
#include "../header/_GLOBALS.h"

_BaseRectangle::_BaseRectangle()
    : _BaseRectangle(sf::Vector2f(100, 100), sf::Vector2f(300, 50), COLOR_RED_DENSE_ROSE, COLOR_GRAYSCALE_BLACK, true)
{
}
_BaseRectangle::_BaseRectangle(sf::Vector2f position, sf::Vector2f size, sf::Color fillColor, sf::Color outlineColor, bool isActive)
    : m_position(position), m_size(size), m_fillColor(fillColor),
      m_outlineColor(outlineColor), m_isActive(isActive)
{
  m_shape.setPosition(m_position);
  m_shape.setSize(m_size);
  m_shape.setOrigin(sf::Vector2f(size.x / 2.f, size.y / 2.f));
  m_shape.setFillColor(m_fillColor);
  m_shape.setOutlineColor(m_outlineColor);
  m_shape.setOutlineThickness(1);
}

_BaseRectangle::~_BaseRectangle()
{
}

void _BaseRectangle::update(sf::Time &delta)
{
}

void _BaseRectangle::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if (m_isActive)
  {
    target.draw(m_shape, states);
  }
}

// --- Setters ---

void _BaseRectangle::setPosition(sf::Vector2f position)
{
  m_position = position;
  m_shape.setPosition(m_position);
}

void _BaseRectangle::setSize(sf::Vector2f size)
{
  m_size = size;
  m_shape.setSize(m_size);
  m_shape.setOrigin(sf::Vector2f(size.x / 2.f, size.y / 2.f));
}

void _BaseRectangle::setFillColor(sf::Color fillColor)
{
  m_fillColor = fillColor;
  m_shape.setFillColor(m_fillColor);
}

void _BaseRectangle::setOutlineColor(sf::Color outlineColor)
{
  m_outlineColor = outlineColor;
  m_shape.setOutlineColor(m_outlineColor);
}

void _BaseRectangle::setColors(sf::Color fillColor, sf::Color outlineColor)
{
  m_fillColor = fillColor;
  m_outlineColor = outlineColor;
  setFillColor(fillColor);
  setOutlineColor(outlineColor);
}

void _BaseRectangle::setActive(bool isActive)
{
  m_isActive = isActive;
}

void _BaseRectangle::toggleActive()
{
  m_isActive = !m_isActive;
}