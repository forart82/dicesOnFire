#include "../header/DebugBar.h"
#include <iostream>

DebugBar::DebugBar(GameText *debugText) : m_isActive(false)
{
  this->m_debugText = debugText;
  this->m_debugText->setPosition({100, 100});
}

DebugBar::~DebugBar()
{
}

void DebugBar::update(sf::Time timePerFrame, sf::Time timeSinceLastUpdate)
{
}

void DebugBar::draw(sf::RenderWindow &window)
{
  if (this->m_isActive)
  {
    this->m_debugWindow.draw(window);
    this->m_debugText->draw(window);
  }
}

void DebugBar::toggleActive()
{
  this->m_isActive = !this->m_isActive;
}