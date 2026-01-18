#include "../header/DebugWindow.h"
#include "../header/_GLOBALS.h"
#include <SFML/Graphics.hpp>

DebugWindow::DebugWindow()
{
  m_backgroundShape.setFillColor(COLOR_GRAYSCALE_DENSE_DARK_GRAY);
  m_backgroundShape.setSize({GLOBAL_SCREEN_WIDTH, GLOBAL_SCREEN_HEIGHT});
  m_backgroundShape.setPosition({0.f, 0.f});

  // Blanks
  m_upBlankShape.setFillColor(COLOR_BLUE_DENSE_DEEP_BLUE);
  m_upBlankShape.setSize({GLOBAL_SCREEN_WIDTH, 50});
  m_upBlankShape.setPosition({0.f, 0.f});

  m_righttBlankShape.setFillColor(COLOR_RED_DENSE_BURGUNDY);
  m_righttBlankShape.setSize({50, GLOBAL_SCREEN_HEIGHT});
  m_righttBlankShape.setPosition({GLOBAL_SCREEN_WIDTH - 50.f, 0.f});

  m_downtBlankShape.setFillColor(COLOR_ORANGE_DENSE_GOLD);
  m_downtBlankShape.setSize({GLOBAL_SCREEN_WIDTH, 50});
  m_downtBlankShape.setPosition({0.f, GLOBAL_SCREEN_HEIGHT - 50.f});

  m_leftBlankShape.setFillColor(COLOR_GREEN_DENSE_GREEN);
  m_leftBlankShape.setSize({50, GLOBAL_SCREEN_HEIGHT});
  m_leftBlankShape.setPosition({0.f, 0.f});

  // Lines
  m_upLineShape.setFillColor(COLOR_BLUE_DEEP_BLUE);
  m_upLineShape.setSize({GLOBAL_SCREEN_WIDTH, 3});
  m_upLineShape.setPosition({0.f, 0.f});

  m_righttLineShape.setFillColor(COLOR_BLUE_DEEP_BLUE);
  m_righttLineShape.setSize({3, GLOBAL_SCREEN_HEIGHT});
  m_righttLineShape.setPosition({GLOBAL_SCREEN_WIDTH - 3.f, 0.f});

  m_downtLineShape.setFillColor(COLOR_BLUE_DEEP_BLUE);
  m_downtLineShape.setSize({GLOBAL_SCREEN_WIDTH, 3});
  m_downtLineShape.setPosition({0.f, GLOBAL_SCREEN_HEIGHT - 3.f});

  m_leftLineShape.setFillColor(COLOR_BLUE_DEEP_BLUE);
  m_leftLineShape.setSize({3, GLOBAL_SCREEN_HEIGHT});
  m_leftLineShape.setPosition({0.f, 0.f});
}

DebugWindow::~DebugWindow() {}

void DebugWindow::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

  target.draw(m_backgroundShape, states);
  target.draw(m_upBlankShape, states);
  target.draw(m_righttBlankShape, states);
  target.draw(m_downtBlankShape, states);
  target.draw(m_leftBlankShape, states);
  target.draw(m_upLineShape, states);
  target.draw(m_righttLineShape, states);
  target.draw(m_downtLineShape, states);
  target.draw(m_leftLineShape, states);
}