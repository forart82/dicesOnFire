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

  void addPosition(const sf::Vector2f &offset);

  void setInner(const Rectangle &inner);
  void setOuter(const Rectangle &outer);

  const Rectangle &getOuter() const;
  const Rectangle &getInner() const;
};