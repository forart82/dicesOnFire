#pragma once

#include <SFML/Graphics.hpp>

#include "Entity/BaseEntity.h"

class Rectangle : public BaseEntity, public sf::Drawable
{

protected:
  sf::RectangleShape m_shape;
  bool m_isActive;

public:
  Rectangle();
  ~Rectangle();

  void update(sf::Time &delta);
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  void move(const sf::Vector2f &movement);
  void addPosition(const sf::Vector2f &offset);
  void toggleActive();

  void setRectangle(const Rectangle &rectangle);
  void setPosition(const sf::Vector2f &position);
  void setSize(const sf::Vector2f &size);
  void setOutlineThickness(int outlineThickness);
  void setOrigin();
  void setColors(const sf::Color &fillColor, const sf::Color &outlineColor);
  void setIsActive(bool isActive);

  const sf::RectangleShape &getShape() const;
  bool getIsActive() const;
};