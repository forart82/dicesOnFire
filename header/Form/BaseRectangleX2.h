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
                sf::Vector2f(200, 1000),
                sf::Vector2f(300, 50),
                1,
                true,
                colors::COLOR_RED_MILKY_ROSE,
                colors::COLOR_GRAYSCALE_BLACK),
            BaseRectangle(
                sf::Vector2f(200, 1000),
                sf::Vector2f(300, 50),
                1,
                true,
                colors::COLOR_GREEN_DARK_GREEN,
                colors::COLOR_GREEN_DARK_GREEN))
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
    m_outer.draw(target, states);
    m_inner.draw(target, states);
  }

  const BaseRectangle &getOuter() const
  {
    return m_outer;
  }

  BaseRectangle &getInner()
  {
    return m_inner;
  }
};