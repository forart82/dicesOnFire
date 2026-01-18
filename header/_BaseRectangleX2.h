#pragma once

#include <SFML/Graphics.hpp>

class _BaseRectangleX2 : public sf::Drawable
{

protected:
  sf::RectangleShape m_outerShape;
  sf::Vector2f m_outerPosition;
  sf::Vector2f m_outerSize;
  sf::Color m_outerFillColor;
  sf::Color m_outerOutlineColor;

  sf::RectangleShape m_innerShape;
  sf::Vector2f m_innerPosition;
  sf::Vector2f m_innerSize;
  sf::Color m_innerFillColor;
  sf::Color m_innerOutlineColor;
  float m_innerPadding;

  bool m_isActive;

public:
  _BaseRectangleX2();
  _BaseRectangleX2(
      sf::Vector2f outerPosition, sf::Vector2f outerSize, sf::Color outerFillColor, sf::Color outerOutlineColor,
      sf::Vector2f innerPosition, sf::Vector2f innerSize, sf::Color innerFillColor, sf::Color innerOutlineColor,
      float innerPadding, bool isActive);
  ~_BaseRectangleX2();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  // Outer
  void setOuterPosition(sf::Vector2f position);
  void setOuterSize(sf::Vector2f size);
  void setOuterFillColor(sf::Color filleColor);
  void setOuterOutlineColor(sf::Color outlineColor);
  void setOuterColors(sf::Color fillColor, sf::Color outlineColor);

  // Inner
  void setInnerPosition(sf::Vector2f position);
  void setInnerSize(sf::Vector2f size);
  void setInnerFillColor(sf::Color filleColor);
  void setInnerOutlineColor(sf::Color outlineColor);
  void setInnerColors(sf::Color fillColor, sf::Color outlineColor);
  void setInnerPadding(float innerPadding);

  void setActive(bool isActive);
  void toggleActive();
};