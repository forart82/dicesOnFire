#include <SFML/Graphics.hpp>
#include "../header/_BaseRectangleX2.h"
#include "../header/_GLOBALS.h"

_BaseRectangleX2::_BaseRectangleX2()
    : _BaseRectangleX2(
          sf::Vector2f(200, 1000), sf::Vector2f(300, 50), COLOR_RED_MILKY_ROSE, COLOR_GRAYSCALE_BLACK,
          sf::Vector2f(200, 1000), sf::Vector2f(300, 50), COLOR_GREEN_DARK_GREEN, COLOR_GREEN_DARK_GREEN,
          5, true)
{
}
_BaseRectangleX2::_BaseRectangleX2(
    sf::Vector2f outerPosition, sf::Vector2f outerSize, sf::Color outerFillColor, sf::Color outerOutlineColor,
    sf::Vector2f innerPosition, sf::Vector2f innerSize, sf::Color innerFillColor, sf::Color innerOutlineColor,
    float innerPadding, bool isActive)
    : m_outerPosition(outerPosition), m_outerSize(outerSize), m_outerFillColor(outerFillColor), m_outerOutlineColor(outerOutlineColor),
      m_innerPosition(innerPosition), m_innerSize(innerSize), m_innerFillColor(innerFillColor), m_innerOutlineColor(innerOutlineColor),
      m_innerPadding(innerPadding), m_isActive(isActive)
{
  m_outerShape.setPosition(m_outerPosition);
  m_outerShape.setSize(m_outerSize);
  m_outerShape.setOrigin({m_outerSize.x / 2.f, m_outerSize.y / 2.f});
  m_outerShape.setFillColor(m_outerFillColor);
  m_outerShape.setOutlineColor(m_outerOutlineColor);
  m_outerShape.setOutlineThickness(1);

  // m_innerShape.setPosition({m_innerPosition.x + m_innerPadding, m_innerPosition.y + m_innerPadding});
  m_innerShape.setPosition(m_outerPosition);
  m_innerShape.setSize({m_innerSize.x - m_innerPadding * 2, m_innerSize.y - m_innerPadding * 2});
  m_innerShape.setOrigin({(m_outerSize.x - m_innerPadding * 2) / 2.f, (m_outerSize.y - m_innerPadding * 2) / 2.f});
  m_innerShape.setFillColor(m_innerFillColor);
  m_innerShape.setOutlineColor(m_innerOutlineColor);
  m_innerShape.setOutlineThickness(1);
}

_BaseRectangleX2::~_BaseRectangleX2()
{
}

void _BaseRectangleX2::update(sf::Time &delta)
{
}

void _BaseRectangleX2::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if (m_isActive)
  {
    target.draw(m_outerShape, states);
    // target.draw(m_innerShape, states);
  }
}

void _BaseRectangleX2::setOuterPosition(sf::Vector2f position)
{
  m_outerPosition = position;
  m_outerShape.setPosition(m_outerPosition);
}

void _BaseRectangleX2::setOuterSize(sf::Vector2f size)
{
  m_outerSize = size;
  m_outerShape.setSize(m_outerSize);
  m_outerShape.setOrigin({m_outerSize.x / 2, m_outerSize.y / 2});
}

void _BaseRectangleX2::setOuterFillColor(sf::Color fillColor)
{
  m_outerFillColor = fillColor;
  m_outerShape.setFillColor(m_outerFillColor);
}

void _BaseRectangleX2::setOuterOutlineColor(sf::Color outlineColor)
{
  m_outerOutlineColor = outlineColor;
  m_outerShape.setOutlineColor(m_outerOutlineColor);
}

void _BaseRectangleX2::setOuterColors(sf::Color fillColor, sf::Color outlineColor)
{
  m_outerFillColor = fillColor;
  m_outerOutlineColor = outlineColor;
  setOuterFillColor(fillColor);
  setOuterOutlineColor(outlineColor);
}

void _BaseRectangleX2::setInnerPosition(sf::Vector2f position)
{
  m_innerPosition = position;
  m_innerShape.setPosition(m_innerPosition);
}

void _BaseRectangleX2::setInnerSize(sf::Vector2f size)
{
  m_innerSize = size;
  // m_innerShape.setSize(m_innerSize);
  // m_innerShape.setOrigin({m_innerSize.x / 2, m_innerSize.y / 2});
  m_innerShape.setSize({m_innerSize.x, m_innerSize.y});
  // m_innerShape.setOrigin({(m_innerSize.x - m_innerPadding * 2) / 2.f, (m_innerSize.y - m_innerPadding * 2) / 2.f});
}

void _BaseRectangleX2::setInnerFillColor(sf::Color fillColor)
{
  m_innerFillColor = fillColor;
  m_innerShape.setFillColor(m_innerFillColor);
}

void _BaseRectangleX2::setInnerOutlineColor(sf::Color outlineColor)
{
  m_innerOutlineColor = outlineColor;
  m_innerShape.setOutlineColor(m_innerOutlineColor);
}

void _BaseRectangleX2::setInnerColors(sf::Color fillColor, sf::Color outlineColor)
{
  m_innerFillColor = fillColor;
  m_innerOutlineColor = outlineColor;
  setInnerFillColor(fillColor);
  setInnerOutlineColor(outlineColor);
}

void _BaseRectangleX2::setInnerPadding(float padding)
{
  m_innerPadding = padding;
}

void _BaseRectangleX2::setActive(bool isActive)
{
  m_isActive = isActive;
}

void _BaseRectangleX2::toggleActive()
{
  m_isActive = !m_isActive;
}