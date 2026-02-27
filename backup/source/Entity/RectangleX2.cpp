#include "Entity/RectangleX2.h"

RectangleX2::RectangleX2() {}

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

void RectangleX2::move(const sf::Vector2f &movement)
{
  m_inner.move(movement);
  m_outer.move(movement);
}

void RectangleX2::addPosition(const sf::Vector2f &offset)
{
  sf::Vector2f newOuterPosition = m_outer.getShape().getPosition() + offset;
  m_outer.setPosition(newOuterPosition);
  sf::Vector2f newInnerPosition = m_inner.getShape().getPosition() + offset;
  m_inner.setPosition(newInnerPosition);
}

void RectangleX2::setRectangleX2(const RectangleX2 &rectangleX2)
{
  m_inner.setRectangle(rectangleX2.getInner());
  m_outer.setRectangle(rectangleX2.getOuter());
}

void RectangleX2::setOuter(const Rectangle &outer)
{
  m_outer.setRectangle(outer);
}

void RectangleX2::setInner(const Rectangle &inner)
{
  m_inner.setRectangle(inner);
}

void RectangleX2::setOuterPosition(const sf::Vector2f &position)
{
  m_outer.setPosition(position);
}
void RectangleX2::setInnerPosition(const sf::Vector2f &position)
{
  m_inner.setPosition(position);
}

void RectangleX2::setOuterSize(const sf::Vector2f &size)
{
  m_outer.setSize(size);
}
void RectangleX2::setInnerSize(const sf::Vector2f &size)
{
  m_inner.setSize(size);
}

const Rectangle &RectangleX2::getOuter() const
{
  return m_outer;
}

const Rectangle &RectangleX2::getInner() const
{
  return m_inner;
}