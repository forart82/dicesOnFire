#include "../header/DebugBar.h"
#include <iostream>

DebugBar::DebugBar() : m_isActive(false)
{
  m_debugText.setPosition({100, 100});
}

DebugBar::~DebugBar()
{
}

void DebugBar::update(sf::Time &delta)
{
  m_debugText.addText("fps", "Target FPS: 60");
  m_debugText.addText("fpsvalue", "FPS: " + std::to_string(1.0f / delta.asSeconds()));
  m_debugText.addText("fpsdelta", "Time since last update: " + std::to_string(delta.asSeconds()));
  m_debugText.addText("random", std::to_string(std::rand() % 100000));
}

void DebugBar::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if (m_isActive)
  {
    target.draw(m_debugWindow, states);
    target.draw(m_debugText, states);
  }
}

void DebugBar::toggleActive()
{
  m_isActive = !m_isActive;
}

GameText DebugBar::getDebugText()
{
  return m_debugText;
}