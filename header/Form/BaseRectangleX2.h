#pragma once

#include <SFML/Graphics.hpp>
#include "Form/BaseRectangle.h"
#include "_COLORS.h"

class BaseRectangleX2 : public sf::Drawable
{

protected:
  BaseRectangle m_outer;
  BaseRectangle m_inner;

public:
  BaseRectangleX2()
      : BaseRectangleX2(
            BaseRectangle(
                sf::Vector2f(200, 200),
                sf::Vector2f(200, 200),
                1,
                true,
                colors::COLOR_BLUE_SKY_BLUE,
                colors::COLOR_BLUE_SKY_BLUE),
            BaseRectangle(
                sf::Vector2f(1000, 1000),
                sf::Vector2f(200, 200),
                1,
                true,
                colors::COLOR_GREEN_GREEN,
                colors::COLOR_GREEN_GREEN))
  {
  }
  BaseRectangleX2(
      BaseRectangle outer,
      BaseRectangle inner)
      : m_outer(outer),
        m_inner(inner)
  {
  }

  ~BaseRectangleX2()
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

  BaseRectangle &getOuter()
  {
    return m_outer;
  }

  BaseRectangle &getInner()
  {
    return m_inner;
  }
};