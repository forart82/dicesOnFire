#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Game.h"

class Dragable
{
protected:
  Game &m_game;

  bool m_isDragged;
  sf::Vector2f m_dragOffset;
  sf::Vector2f m_originalPosition;

  // The child classes MUST implement these so Dragable can do the math
  virtual const sf::FloatRect &getGlobalBounds() const = 0;
  virtual const sf::Vector2f &getPosition() const = 0;
  virtual void setPosition(const sf::Vector2f &position) = 0;

public:
  Dragable(Game &game);
  virtual ~Dragable() = default;

  // 1. Triggered when the mouse is pressed. Returns true if this item was clicked.
  virtual bool startDrag(const sf::Vector2f &mousePos);

  // 2. Triggered every frame if m_isDragged == true
  virtual void updateDrag(const sf::Vector2f &mousePos);

  // 3. Triggered when mouse is released
  virtual void stopDrag();

  // 4. Call this if the drop was invalid
  virtual void cancelDrag();

  bool getIsDragged() const;
};