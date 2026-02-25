#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Rectangle.h"

class Dragable
{
private:
  Rectangle *m_dragableBody;

protected:
  bool m_isDragged;
  sf::Vector2f m_dragOffset;
  sf::Vector2f m_originalPosition;

  // The child classes MUST implement these so Dragable can do the math

public:
  Dragable();
  ~Dragable() = default;

  void bind(Rectangle *body);

  bool startDrag(const sf::Vector2f &mousePos);
  void updateDrag(const sf::Vector2f &mousePos);
  void stopDrag();
  void cancelDrag();

  const sf::Vector2f &getDragableCenter() const;
  bool getIsDragged() const;
};