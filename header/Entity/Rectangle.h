#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Entity/Game.h"
#include "Globals/Colors.h"

class Rectangle : public sf::Drawable
{

protected:
  Game &m_game;

  sf::RectangleShape m_body;
  bool m_isActive;

public:
  Rectangle(Game &game);
  ~Rectangle();

  void update(sf::Time &delta);
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  void addPosition(const sf::Vector2f &offset);
  void toggleActive();

  void setBody(const Rectangle &baseRectangle);
  void setOriginFromSize(const sf::Vector2f &size);
  void setIsActive(bool isActive);

  const sf::RectangleShape &getShape() const;
  bool getIsActive() const;
};