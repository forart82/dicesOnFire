#include "../header/DebugBar.h"
#include <iostream>

DebugBar::DebugBar() : m_isActive(false)
{
  this->m_debugText.setPosition({100, 100});
}

DebugBar::~DebugBar()
{
}

void DebugBar::update(sf::Time &delta)
{
  this->m_debugText.addText("fps", "Target FPS: 60");
  this->m_debugText.addText("fpsvalue", "FPS: " + std::to_string(1.0f / delta.asSeconds()));
  this->m_debugText.addText("fpsdelta", "Time since last update: " + std::to_string(delta.asSeconds()));
  this->m_debugText.addText("random", std::to_string(std::rand() % 100000));
}

void DebugBar::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if (this->m_isActive)
  {
    target.draw(this->m_debugWindow, states);
    target.draw(this->m_debugText, states);
  }
}

void DebugBar::toggleActive()
{
  this->m_isActive = !this->m_isActive;
}

GameText DebugBar::getDebugText()
{
  return this->m_debugText;
}