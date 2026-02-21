#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Game.h"
#include "Globals/Colors.h"

class Circle : public sf::Drawable
{

protected:
  Game &m_game;

  sf::CircleShape m_body;
  bool m_isActive;

public:
  Circle(Game &game)
      : m_game(game),
        m_isActive(true)
  {
  }

  ~Circle()
  {
  }

  void update(sf::Time &delta);
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  void move(const sf::Vector2f &movement);
  void addPosition(const sf::Vector2f &offset);
  void toggleActive();

  void setBody(const Circle &body);
  void setPosition(const sf::Vector2f &position);
  void setRadius(int radius);
  void setOrigin(const sf::Vector2f &origin);
  void setColors(const sf::Color &fillColor, const sf::Color &outlineColor);
  void setActive(bool isActive);

  const sf::CircleShape &getBody() const
};