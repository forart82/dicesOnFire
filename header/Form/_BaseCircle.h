#pragma once

#include <SFML/Graphics.hpp>

class _BaseCircle : public sf::Drawable
{

protected:
  sf::Vector2f m_position;
  sf::CircleShape m_shape;
  sf::Color m_fillColor;
  sf::Color m_outlineColor;
  float m_radius;
  bool m_isActive;

public:
  _BaseCircle();
  _BaseCircle(sf::Vector2f position, float radius, sf::Color fillColor, sf::Color outlineColor, bool isActive);
  ~_BaseCircle();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void setPosition(sf::Vector2f position);
  void setRadius(float radius);
  void setFillColor(sf::Color filleColor);
  void setOutlineColor(sf::Color outlineColor);
  void setColors(sf::Color fillColor, sf::Color outlineColor);
  void setActive(bool isActive);

  void toggleActive();
};