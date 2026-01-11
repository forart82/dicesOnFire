#include "../header/DebugBar.h"
#include <iostream>

DebugBar::DebugBar(GameText *debugText) : m_isActive(false)
{
  this->m_debugText = debugText;
}

DebugBar::~DebugBar()
{
}

void DebugBar::update(sf::Time timePerFrame, sf::Time timeSinceLastUpdate)
{

  // std::stringstream ss;
  // ss << "Target FPS: 60\n";
  // ss << "Time per frame: " << timePerFrame.asSeconds() << " s\n";
  // ss << "Time since last update: " << timeSinceLastUpdate.asSeconds() << " s\n";
  // this->m_text.setString(ss.str());
}

void DebugBar::draw(sf::RenderWindow &window)
{
  if (this->m_isActive)
  {
    std::cout << this->m_debugText->getText() << std::endl;
    window.draw(this->m_debugText->getSfText());
    this->m_debugText->removeText();
  }
}

void DebugBar::toggleActive()
{
  this->m_isActive = !this->m_isActive;
}