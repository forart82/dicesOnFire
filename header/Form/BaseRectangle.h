#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include "_COLORS.h"

class BaseRectangle : public sf::Drawable
{

protected:
  sf::RectangleShape m_shape;
  sf::Vector2f m_position;
  sf::Vector2f m_size;
  int m_thickness;
  bool m_isActive;
  sf::Color m_fillColor;
  sf::Color m_outlineColor;

public:
  BaseRectangle()
      : BaseRectangle(
            sf::Vector2f(100, 100),
            sf::Vector2f(300, 50),
            1,
            true,
            colors::COLOR_RED_DENSE_ROSE,
            colors::COLOR_GRAYSCALE_BLACK)
  {
  }
  BaseRectangle(
      sf::Vector2f position,
      sf::Vector2f size,
      int thickness,
      bool isActive,
      sf::Color fillColor,
      sf::Color outlineColor)
      : m_position(position),
        m_size(size),
        m_thickness(thickness),
        m_isActive(isActive),
        m_fillColor(fillColor),
        m_outlineColor(outlineColor)
  {
    m_shape.setPosition({std::round(m_position.x), std::round(m_position.y)});
    m_shape.setSize({std::round(m_size.x), std::round(m_size.y)});
    m_shape.setOutlineThickness(m_thickness);
    m_shape.setFillColor(m_fillColor);
    m_shape.setOutlineColor(m_outlineColor);

    m_shape.setOrigin({std::round(size.x / 2.f), std::round(size.y / 2.f)});
  }

  ~BaseRectangle()
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
    m_shape.setPosition({std::round(m_position.x), std::round(m_position.y)});
  }

  void setSize(sf::Vector2f size)
  {
    m_size = size;
    m_shape.setSize({std::round(m_size.x), std::round(m_size.y)});
    m_shape.setOrigin({std::round(size.x / 2.f), std::round(size.y / 2.f)});
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

  const sf::Vector2f &getPosition() const
  {
    return m_position;
  }

  const sf::Vector2f &getSize() const
  {
    return m_size;
  }
};