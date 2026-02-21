#include "Ability/Dragable.h"

Dragable::Dragable(
    Game &game)
    : m_game(game),
      m_isDragged(false)
{
}

bool Dragable::startDrag(const sf::Vector2f &mousePos)
{
  if (getGlobalBounds().contains(mousePos))
  {
    m_isDragged = true;
    m_originalPosition = getPosition(); // Save where we started

    // Calculate the offset so the item doesn't teleport to the mouse
    m_dragOffset = mousePos - m_originalPosition;
    return true;
  }
  return false;
}

void Dragable::updateDrag(const sf::Vector2f &mousePos)
{
  if (m_isDragged)
  {
    // Move the item to the mouse, minus the initial click offset
    setPosition(mousePos - m_dragOffset);
  }
}

void Dragable::stopDrag()
{
  m_isDragged = false;
  // Here, your Game or Hub will usually check WHERE it was dropped
}

void Dragable::cancelDrag()
{
  m_isDragged = false;
  setPosition(m_originalPosition); // Snap back to start!
}

bool Dragable::getIsDragged() const
{
  return m_isDragged;
}