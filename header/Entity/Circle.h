#pragma once

#include <cmath>
#include "Entity/BaseEntity.h"
#include "Globals/Colors.h"

class Circle : public BaseEntity, public sf::Drawable
{

protected:
  sf::CircleShape m_shape;
  bool m_isActive;

public:
  Circle();
  ~Circle();

  void update(sf::Time &delta);
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  void move(const sf::Vector2f &movement);
  void addPosition(const sf::Vector2f &offset);
  void toggleActive();

  void setCircle(const Circle &circle);
  void setPosition(const sf::Vector2f &position);
  void setRadius(int radius);
  void setOutlineThickness(int outlineTickness);
  void setOrigin();
  void setPointCount(size_t points);
  void setColors(const sf::Color &fillColor, const sf::Color &outlineColor);
  void setIsActive(bool isActive);

  const sf::CircleShape &getShape() const;
};