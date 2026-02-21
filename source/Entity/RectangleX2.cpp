#include "Entity/RectangleX2.h"

RectangleX2::RectangleX2(Game &game)
    : m_game(game)
{
}

RectangleX2::~RectangleX2() {}

void RectangleX2::update(sf::Time &delta)
{
  m_outer.update(delta);
  m_inner.update(delta);
}

void RectangleX2::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(m_outer);
  target.draw(m_inner);
}

void RectangleX2::addPosition(const sf::Vector2f &offset)
{
  sf::Vector2f newOuterPosition = m_outer.getShape().getPosition() + offset;
  m_outer.getShape().setPosition(newOuterPosition);
  sf::Vector2f newInnerPosition = m_inner.getShape().getPosition() + offset;
  m_inner.getShape().setPosition(newInnerPosition);
}

void RectangleX2::setInner(const Rectangle &inner)
{
  m_inner = inner;
}

void RectangleX2::setOuter(const Rectangle &outer)
{
  m_outer = outer;
}

const Rectangle &RectangleX2::getOuter() const
{
  return m_outer;
}

const Rectangle &RectangleX2::getInner() const
{
  return m_inner;
}