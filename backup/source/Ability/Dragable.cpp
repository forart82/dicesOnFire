#include "Ability/Dragable.h"

Dragable::Dragable()
    : m_isDragged(false)
{
}

void Dragable::bind(Rectangle *body)
{
  m_dragableBody = body;
}

bool Dragable::startDrag(const sf::Vector2f &mousePos)
{
  if (m_dragableBody->getShape().getGlobalBounds().contains(mousePos))
  {
    m_isDragged = true;
    m_originalPosition = m_dragableBody->getShape().getPosition(); // Save where we started

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
    m_dragableBody->setPosition(mousePos - m_dragOffset);
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
  m_dragableBody->setPosition(m_originalPosition); // Snap back to start!
}

const sf::Vector2f &Dragable::getDragableCenter() const
{
  return m_dragableBody->getShape().getGeometricCenter();
}

bool Dragable::getIsDragged() const
{
  return m_isDragged;
}