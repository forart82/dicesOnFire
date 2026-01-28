#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include "_COLORS.h"

class BaseRectangle : public sf::Drawable
{

protected:
  sf::RectangleShape m_shape;
  int m_thickness;
  bool m_isActive;

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
      : m_thickness(thickness),
        m_isActive(isActive)
  {
    m_shape.setPosition({std::round(position.x), std::round(position.y)});
    m_shape.setSize({std::round(size.x), std::round(size.y)});
    m_shape.setOutlineThickness(m_thickness);
    m_shape.setFillColor(fillColor);
    m_shape.setOutlineColor(outlineColor);

    this->setOriginFromSize(size);
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
  void setBaseRectangle(BaseRectangle baseRectangle)
  {
    m_shape.setPosition(baseRectangle.m_shape.getPosition());
    m_shape.setSize(baseRectangle.m_shape.getSize());
    setThickness(baseRectangle.getThickness());
    setIsActive(baseRectangle.getIsActive());
    m_shape.setFillColor(baseRectangle.m_shape.getFillColor());
    m_shape.setOutlineColor(baseRectangle.m_shape.getOutlineColor());

    setOriginFromSize(baseRectangle.m_shape.getSize());
  }

  void setOriginFromSize(sf::Vector2f size)
  {
    m_shape.setOrigin({std::round(size.x / 2.f), std::round(size.y / 2.f)});
  }

  void setThickness(int thickness)
  {
    m_thickness = thickness;
  }

  void setIsActive(bool isActive)
  {
    m_isActive = isActive;
  }

  void toggleActive()
  {
    m_isActive = !m_isActive;
  }

  sf::RectangleShape &getShape()
  {
    return m_shape;
  }

  int &getThickness()
  {
    return m_thickness;
  }

  bool &getIsActive()
  {
    return m_isActive;
  }
};