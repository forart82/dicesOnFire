#pragma once

#include <SFML/Graphics.hpp>

class _BaseRectangle : public sf::Drawable
{

protected:
  sf::RectangleShape m_shape;
  sf::Vector2f m_position;
  sf::Vector2f m_size;
  sf::Color m_fillColor;
  sf::Color m_outlineColor;
  bool m_isActive;

public:
  _BaseRectangle();
  _BaseRectangle(sf::Vector2f position, sf::Vector2f size, sf::Color fillColor, sf::Color outlineColor, bool isActive);
  ~_BaseRectangle();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void setPosition(sf::Vector2f position);
  void setSize(sf::Vector2f size);
  void setFillColor(sf::Color filleColor);
  void setOutlineColor(sf::Color outlineColor);
  void setColors(sf::Color fillColor, sf::Color outlineColor);
  void setActive(bool isActive);

  void toggleActive();
};