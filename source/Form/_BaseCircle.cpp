#include <SFML/Graphics.hpp>
#include "Form/_BaseCircle.h"
#include "_GLOBALS.h"

_BaseCircle::_BaseCircle()
    : _BaseCircle(sf::Vector2f(100, 100), 50, COLOR_RED_DENSE_ROSE, COLOR_GRAYSCALE_BLACK, true)
{
}
_BaseCircle::_BaseCircle(sf::Vector2f position, float radius, sf::Color fillColor, sf::Color outlineColor, bool isActive)
    : m_position(position), m_radius(radius), m_fillColor(fillColor),
      m_outlineColor(outlineColor), m_isActive(isActive)
{
  m_shape.setPosition(m_position);
  m_shape.setRadius(m_radius);
  m_shape.setOrigin({m_radius, m_radius});
  m_shape.setFillColor(m_fillColor);
  m_shape.setOutlineColor(m_outlineColor);
  m_shape.setOutlineThickness(2);
}

_BaseCircle::~_BaseCircle()
{
}

void _BaseCircle::update(sf::Time &delta)
{
}

void _BaseCircle::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if (m_isActive)
  {
    target.draw(m_shape, states);
  }
}

// --- Setters ---

void _BaseCircle::setPosition(sf::Vector2f position)
{
  m_position = position;
  m_shape.setPosition(m_position);
}

void _BaseCircle::setRadius(float radius)
{
  m_radius = radius;
  m_shape.setRadius(m_radius);
  m_shape.setOrigin({m_radius, m_radius});
}

void _BaseCircle::setFillColor(sf::Color fillColor)
{
  m_fillColor = fillColor;
  m_shape.setFillColor(m_fillColor);
}

void _BaseCircle::setOutlineColor(sf::Color outlineColor)
{
  m_outlineColor = outlineColor;
  m_shape.setOutlineColor(m_outlineColor);
}

void _BaseCircle::setColors(sf::Color fillColor, sf::Color outlineColor)
{
  m_fillColor = fillColor;
  m_outlineColor = outlineColor;
  setFillColor(fillColor);
  setOutlineColor(outlineColor);
}

void _BaseCircle::setActive(bool isActive)
{
  m_isActive = isActive;
}

void _BaseCircle::toggleActive()
{
  m_isActive = !m_isActive;
}