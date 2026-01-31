#pragma once

#include <SFML/Graphics.hpp>
#include "_COLORS.h"

class BaseCircle : public sf::Drawable
{

protected:
  sf::CircleShape m_shape;
  sf::Vector2f m_position;
  float m_radius;
  int m_thickness;
  bool m_isActive;
  sf::Color m_fillColor;
  sf::Color m_outlineColor;

public:
  BaseCircle()
      : BaseCircle(
            sf::Vector2f(1000, 1000),
            50,
            1,
            true,
            colors::COLOR_RED_HOT_PINK,
            colors::COLOR_RED_HOT_PINK)
  {
  }
  BaseCircle(
      sf::Vector2f position,
      float radius,
      int thickness,
      bool isActive,
      sf::Color fillColor,
      sf::Color outlineColor)
      : m_position(position),
        m_radius(radius),
        m_thickness(thickness),
        m_isActive(isActive),
        m_fillColor(fillColor),
        m_outlineColor(outlineColor)
  {
    m_shape.setPosition(m_position);
    m_shape.setRadius(m_radius);
    m_shape.setOutlineThickness(m_thickness);
    m_shape.setOrigin({m_radius, m_radius});
    m_shape.setFillColor(m_fillColor);
    m_shape.setOutlineColor(m_outlineColor);
  }

  ~BaseCircle()
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

  // --- Setters ---

  void setPosition(sf::Vector2f position)
  {
    m_position = position;
    m_shape.setPosition(m_position);
  }

  void setRadius(float radius)
  {
    m_radius = radius;
    m_shape.setRadius(m_radius);
    m_shape.setOrigin({m_radius, m_radius});
  }

  void setThickness(int thickness)
  {
    m_thickness = thickness;
  }

  void setActive(bool isActive)
  {
    m_isActive = isActive;
  }

  void setFillColor(sf::Color fillColor)
  {
    m_fillColor = fillColor;
    m_shape.setFillColor(m_fillColor);
  }

  void setOutlineColor(sf::Color outlineColor)
  {
    m_outlineColor = outlineColor;
    m_shape.setOutlineColor(m_outlineColor);
  }

  void setColors(sf::Color fillColor, sf::Color outlineColor)
  {
    m_fillColor = fillColor;
    m_outlineColor = outlineColor;
    setFillColor(fillColor);
    setOutlineColor(outlineColor);
  }

  void toggleActive()
  {
    m_isActive = !m_isActive;
  }
};