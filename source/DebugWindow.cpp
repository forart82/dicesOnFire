#include "../header/DebugWindow.h"
#include "../header/_GLOBALS.h"
#include <SFML/Graphics.hpp>

DebugWindow::DebugWindow()
{
  this->m_background.setFillColor(COLOR_SHADE_DARK_GRAY);
  this->m_background.setSize({GLOBAL_SCREEN_WIDTH, GLOBAL_SCREEN_HEIGHT});
  this->m_background.setPosition({0.f, 0.f});

  // Blanks
  this->m_upBlank.setFillColor(COLOR_SHADE_BLUE);
  this->m_upBlank.setSize({GLOBAL_SCREEN_WIDTH, 50});
  this->m_upBlank.setPosition({0.f, 0.f});

  this->m_righttBlank.setFillColor(COLOR_SHADE_RED);
  this->m_righttBlank.setSize({50, GLOBAL_SCREEN_HEIGHT});
  this->m_righttBlank.setPosition({GLOBAL_SCREEN_WIDTH - 50.f, 0.f});

  this->m_downtBlank.setFillColor(COLOR_SHADE_YELLOW);
  this->m_downtBlank.setSize({GLOBAL_SCREEN_WIDTH, 50});
  this->m_downtBlank.setPosition({0.f, GLOBAL_SCREEN_HEIGHT - 50.f});

  this->m_leftBlank.setFillColor(COLOR_SHADE_GREEN);
  this->m_leftBlank.setSize({50, GLOBAL_SCREEN_HEIGHT});
  this->m_leftBlank.setPosition({0.f, 0.f});

  // Lines
  this->m_upLine.setFillColor(COLOR_DEEP_BLUE);
  this->m_upLine.setSize({GLOBAL_SCREEN_WIDTH, 3});
  this->m_upLine.setPosition({0.f, 0.f});

  this->m_righttLine.setFillColor(COLOR_DEEP_BLUE);
  this->m_righttLine.setSize({3, GLOBAL_SCREEN_HEIGHT});
  this->m_righttLine.setPosition({GLOBAL_SCREEN_WIDTH - 3.f, 0.f});

  this->m_downtLine.setFillColor(COLOR_DEEP_BLUE);
  this->m_downtLine.setSize({GLOBAL_SCREEN_WIDTH, 3});
  this->m_downtLine.setPosition({0.f, GLOBAL_SCREEN_HEIGHT - 3.f});

  this->m_leftLine.setFillColor(COLOR_DEEP_BLUE);
  this->m_leftLine.setSize({3, GLOBAL_SCREEN_HEIGHT});
  this->m_leftLine.setPosition({0.f, 0.f});
}

DebugWindow::~DebugWindow() {}

void DebugWindow::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

  target.draw(this->m_background, states);
  target.draw(this->m_upBlank, states);
  target.draw(this->m_righttBlank, states);
  target.draw(this->m_downtBlank, states);
  target.draw(this->m_leftBlank, states);
  target.draw(this->m_upLine, states);
  target.draw(this->m_righttLine, states);
  target.draw(this->m_downtLine, states);
  target.draw(this->m_leftLine, states);
}