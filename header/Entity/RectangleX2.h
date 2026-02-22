#pragma once

#include "Entity/BaseEntity.h"
#include "Entity/Rectangle.h"

class RectangleX2 : public BaseEntity, public sf::Drawable
{

protected:
  Rectangle m_outer;
  Rectangle m_inner;

public:
  RectangleX2();
  ~RectangleX2();

  void update(sf::Time &delta);

  void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  void move(const sf::Vector2f &movement);
  void addPosition(const sf::Vector2f &offset);

  void setRectangleX2(const RectangleX2 &rectangleX2);
  void setOuter(const Rectangle &outer);
  void setInner(const Rectangle &inner);
  void setOuterPosition(const sf::Vector2f &position);
  void setInnerPosition(const sf::Vector2f &position);
  void setOuterSize(const sf::Vector2f &size);
  void setInnerSize(const sf::Vector2f &size);

  const Rectangle &getOuter() const;
  const Rectangle &getInner() const;
};