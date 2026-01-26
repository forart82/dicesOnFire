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
  void setBaseRectangle(const BaseRectangle baseRectangle)
  {
    sf::Vector2f size = baseRectangle.getSize();
    this->setPosition(baseRectangle.getPosition());
    this->setSize(size);
    this->setThickness(baseRectangle.getThickness());
    this->setIsActive(baseRectangle.getIsActive());
    this->setFillColor(baseRectangle.getFillColor());
    this->setOutlineColor(baseRectangle.getOutlineColor());

    this->setOriginFromSize(size);
  }

  void setPosition(sf::Vector2f position)
  {
    m_shape.setPosition({std::round(position.x), std::round(position.y)});
  }

  void setSize(sf::Vector2f size)
  {
    m_shape.setSize({std::round(size.x), std::round(size.y)});
  }

  void setOrigin(sf::Vector2f origin)
  {
    m_shape.setSize({std::round(origin.x), std::round(origin.y)});
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

  void setFillColor(sf::Color fillColor)
  {
    m_shape.setFillColor(fillColor);
  }

  void setOutlineColor(sf::Color outlineColor)
  {
    m_shape.setOutlineColor(outlineColor);
  }

  void setColors(sf::Color fillColor, sf::Color outlineColor)
  {
    setFillColor(fillColor);
    setOutlineColor(outlineColor);
  }

  void toggleActive()
  {
    m_isActive = !m_isActive;
  }

  sf::Vector2f getPosition() const
  {
    return m_shape.getPosition();
  }

  sf::Vector2f getSize() const
  {
    return m_shape.getSize();
  }

  const int &getThickness() const
  {
    return m_thickness;
  }

  const bool &getIsActive() const
  {
    return m_isActive;
  }

  sf::Color getFillColor() const
  {
    return m_shape.getFillColor();
  }

  sf::Color getOutlineColor() const
  {
    return m_shape.getOutlineColor();
  }
};