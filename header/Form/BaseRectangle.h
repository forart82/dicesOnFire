#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include "_COLORS.h"

class BaseRectangle : public sf::Drawable
{

protected:
  sf::RectangleShape m_shape;
  bool m_isActive;

public:
  BaseRectangle()
      : BaseRectangle(
            sf::Vector2f(300, 300),
            sf::Vector2f(300, 300),
            1,
            true,
            colors::COLOR_RED_RED,
            colors::COLOR_RED_RED)
  {
  }
  BaseRectangle(
      sf::Vector2f position,
      sf::Vector2f size,
      int thickness,
      bool isActive,
      sf::Color fillColor,
      sf::Color outlineColor)
      : m_isActive(isActive)
  {
    m_shape.setPosition({std::round(position.x), std::round(position.y)});
    m_shape.setSize({std::round(size.x), std::round(size.y)});
    m_shape.setOutlineThickness(thickness);
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
    m_shape.setOutlineThickness(baseRectangle.getShape().getOutlineThickness());
    m_shape.setFillColor(baseRectangle.m_shape.getFillColor());
    m_shape.setOutlineColor(baseRectangle.m_shape.getOutlineColor());

    setIsActive(baseRectangle.getIsActive());
    setOriginFromSize(baseRectangle.m_shape.getSize());
  }

  void setOriginFromSize(sf::Vector2f size)
  {
    m_shape.setOrigin({std::round(size.x / 2.f), std::round(size.y / 2.f)});
  }

  void setIsActive(bool isActive)
  {
    m_isActive = isActive;
  }

  void addPosition(sf::Vector2f &offset)
  {
    sf::Vector2f newPosition = m_shape.getPosition() + offset;
    m_shape.setPosition(newPosition);
  }

  void toggleActive()
  {
    m_isActive = !m_isActive;
  }

  sf::RectangleShape &getShape()
  {
    return m_shape;
  }

  bool &getIsActive()
  {
    return m_isActive;
  }
};