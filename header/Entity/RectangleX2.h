#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Rectangle.h"
#include "Globals/Colors.h"

class RectangleX2 : public sf::Drawable
{

protected:
  Rectangle m_outer;
  Rectangle m_inner;

public:
  RectangleX2()
      : RectangleX2(
            Rectangle(
                sf::Vector2f(200, 200),
                sf::Vector2f(200, 200),
                1,
                true,
                colors::COLOR_BLUE_SKY_BLUE,
                colors::COLOR_BLUE_SKY_BLUE),
            Rectangle(
                sf::Vector2f(1000, 1000),
                sf::Vector2f(200, 200),
                1,
                true,
                colors::COLOR_GREEN_GREEN,
                colors::COLOR_GREEN_GREEN))
  {
  }
  RectangleX2(
      Rectangle outer,
      Rectangle inner)
      : m_outer(outer),
        m_inner(inner)
  {
  }

  ~RectangleX2()
  {
  }

  void update(sf::Time &delta)
  {
    m_outer.update(delta);
    m_inner.update(delta);
  }

  void draw(sf::RenderTarget &target, sf::RenderStates states) const
  {
    target.draw(m_outer);
    target.draw(m_inner);
  }

  void addPosition(sf::Vector2f &offset)
  {
    sf::Vector2f newOuterPosition = m_outer.getShape().getPosition() + offset;
    m_outer.getShape().setPosition(newOuterPosition);
    sf::Vector2f newInnerPosition = m_inner.getShape().getPosition() + offset;
    m_inner.getShape().setPosition(newInnerPosition);
  }

  Rectangle &getOuter()
  {
    return m_outer;
  }

  Rectangle &getInner()
  {
    return m_inner;
  }
};