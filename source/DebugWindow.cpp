#include "../header/DebugWindow.h"
#include "../header/_GLOBALS.h"
#include <SFML/Graphics.hpp>

DebugWindow::DebugWindow()
{
  m_background.setFillColor(COLOR_SHADE_DARK_GRAY);
  m_background.setSize({GLOBAL_SCREEN_WIDTH, GLOBAL_SCREEN_HEIGHT});
  m_background.setPosition({0.f, 0.f});

  // Blanks
  m_upBlank.setFillColor(COLOR_SHADE_BLUE);
  m_upBlank.setSize({GLOBAL_SCREEN_WIDTH, 50});
  m_upBlank.setPosition({0.f, 0.f});

  m_righttBlank.setFillColor(COLOR_SHADE_RED);
  m_righttBlank.setSize({50, GLOBAL_SCREEN_HEIGHT});
  m_righttBlank.setPosition({GLOBAL_SCREEN_WIDTH - 50.f, 0.f});

  m_downtBlank.setFillColor(COLOR_SHADE_YELLOW);
  m_downtBlank.setSize({GLOBAL_SCREEN_WIDTH, 50});
  m_downtBlank.setPosition({0.f, GLOBAL_SCREEN_HEIGHT - 50.f});

  m_leftBlank.setFillColor(COLOR_SHADE_GREEN);
  m_leftBlank.setSize({50, GLOBAL_SCREEN_HEIGHT});
  m_leftBlank.setPosition({0.f, 0.f});

  // Lines
  m_upLine.setFillColor(COLOR_DEEP_BLUE);
  m_upLine.setSize({GLOBAL_SCREEN_WIDTH, 3});
  m_upLine.setPosition({0.f, 0.f});

  m_righttLine.setFillColor(COLOR_DEEP_BLUE);
  m_righttLine.setSize({3, GLOBAL_SCREEN_HEIGHT});
  m_righttLine.setPosition({GLOBAL_SCREEN_WIDTH - 3.f, 0.f});

  m_downtLine.setFillColor(COLOR_DEEP_BLUE);
  m_downtLine.setSize({GLOBAL_SCREEN_WIDTH, 3});
  m_downtLine.setPosition({0.f, GLOBAL_SCREEN_HEIGHT - 3.f});

  m_leftLine.setFillColor(COLOR_DEEP_BLUE);
  m_leftLine.setSize({3, GLOBAL_SCREEN_HEIGHT});
  m_leftLine.setPosition({0.f, 0.f});
}

DebugWindow::~DebugWindow() {}

void DebugWindow::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

  target.draw(m_background, states);
  target.draw(m_upBlank, states);
  target.draw(m_righttBlank, states);
  target.draw(m_downtBlank, states);
  target.draw(m_leftBlank, states);
  target.draw(m_upLine, states);
  target.draw(m_righttLine, states);
  target.draw(m_downtLine, states);
  target.draw(m_leftLine, states);
}