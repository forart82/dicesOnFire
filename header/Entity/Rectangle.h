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

  void move(const sf::Vector2f &movement);
  void addPosition(const sf::Vector2f &offset);
  void toggleActive();

  void setBody(const Rectangle &body);
  void setPosition(const sf::Vector2f &position);
  void setOriginFromSize(const sf::Vector2f &size);
  void setIsActive(bool isActive);

  const sf::RectangleShape &getBody() const;
  bool getIsActive() const;
};