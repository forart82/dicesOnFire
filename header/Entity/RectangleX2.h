#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Game.h"
#include "Entity/Rectangle.h"
#include "Globals/Colors.h"

class RectangleX2 : public sf::Drawable
{

protected:
  Game &m_game;

  Rectangle m_outer;
  Rectangle m_inner;

public:
  RectangleX2(Game &game);
  ~RectangleX2();

  void update(sf::Time &delta);

  void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  void move(const sf::Vector2f &movement);
  void addPosition(const sf::Vector2f &offset);

  void setBodyX2(const RectangleX2 &rectangleX2);
  void setOuter(const Rectangle &outer);
  void setInner(const Rectangle &inner);
  void setOuterPosition(const sf::Vector2f &position);
  void setInnerPosition(const sf::Vector2f &position);

  const Rectangle &getOuter() const;
  const Rectangle &getInner() const;
};