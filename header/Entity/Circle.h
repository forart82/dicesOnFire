#pragma once

#include <SFML/Graphics.hpp>
#include "Globals/Colors.h"

class Circle : public sf::Drawable
{

protected:
  sf::CircleShape m_shape;
  bool m_isActive;

public:
  Circle()
      : Circle(
            sf::Vector2f(1000, 1000),
            50,
            1,
            true,
            colors::COLOR_RED_HOT_PINK,
            colors::COLOR_RED_HOT_PINK)
  {
  }
  Circle(
      sf::Vector2f position,
      float radius,
      int thickness,
      bool isActive,
      sf::Color fillColor,
      sf::Color outlineColor)
      : m_isActive(isActive)
  {
    m_shape.setPosition(position);
    m_shape.setRadius(radius);
    m_shape.setOutlineThickness(thickness);
    m_shape.setOrigin({radius, radius});
    setColors(fillColor, outlineColor);
  }

  ~Circle()
  {
  }

  void update(sf::Time &delta)
  {
  }

  void draw(sf::RenderTarget &target, sf::RenderStates states) const
  {
    if (m_isActive)
    {
      target.draw(m_shape, states);
    }
  }

  void addPosition(sf::Vector2f &offset)
  {
    sf::Vector2f newPosition = m_shape.getPosition() + offset;
    m_shape.setPosition(newPosition);
  }

  void setShape(Circle &shape)
  {
    m_shape.setPosition(shape.getShape().getPosition());
    m_shape.setRadius(shape.getShape().getRadius());
    m_shape.setOutlineThickness(shape.getShape().getOutlineThickness());
    m_shape.setOrigin({shape.getShape().getRadius(), shape.getShape().getRadius()});
    setColors(shape.getShape().getFillColor(), shape.getShape().getOutlineColor());
  }

  void setActive(bool isActive)
  {
    m_isActive = isActive;
  }

  void setColors(sf::Color fillColor, sf::Color outlineColor)
  {
    m_shape.setFillColor(fillColor);
    m_shape.setOutlineColor(outlineColor);
  }

  void toggleActive()
  {
    m_isActive = !m_isActive;
  }

  sf::CircleShape &getShape()
  {
    return m_shape;
  }
};