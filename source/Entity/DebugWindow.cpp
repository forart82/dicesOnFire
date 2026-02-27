#include "Entity/DebugWindow.h"

DebugWindow::DebugWindow(int screenWidht, int screenHeight)
    : m_screenWidth(screenWidht),
      m_screenHeight(screenHeight)
{
  m_backgroundShape.setFillColor(colors::COLOR_GRAYSCALE_MILKY_DARK_GRAY);
  m_backgroundShape.setSize(sf::Vector2f(m_screenWidth, m_screenHeight));
  m_backgroundShape.setPosition(sf::Vector2f(0.f, 0.f));

  // Blanks
  m_upBlankShape.setFillColor(colors::COLOR_BLUE_DENSE_DEEP_BLUE);
  m_upBlankShape.setSize(sf::Vector2f(m_screenWidth, 50));
  m_upBlankShape.setPosition(sf::Vector2f(0.f, 0.f));

  m_righttBlankShape.setFillColor(colors::COLOR_RED_DENSE_BURGUNDY);
  m_righttBlankShape.setSize(sf::Vector2f(50, m_screenHeight));
  m_righttBlankShape.setPosition(sf::Vector2f(m_screenWidth - 50.f, 0.f));

  m_downtBlankShape.setFillColor(colors::COLOR_ORANGE_DENSE_GOLD);
  m_downtBlankShape.setSize(sf::Vector2f(m_screenWidth, 50));
  m_downtBlankShape.setPosition(sf::Vector2f(0.f, m_screenHeight - 50.f));

  m_leftBlankShape.setFillColor(colors::COLOR_GREEN_DENSE_GREEN);
  m_leftBlankShape.setSize(sf::Vector2f(50, m_screenHeight));
  m_leftBlankShape.setPosition(sf::Vector2f(0.f, 0.f));

  // Lines
  m_upLineShape.setFillColor(colors::COLOR_BLUE_DEEP_BLUE);
  m_upLineShape.setSize(sf::Vector2f(m_screenWidth, 3));
  m_upLineShape.setPosition(sf::Vector2f(0.f, 0.f));

  m_righttLineShape.setFillColor(colors::COLOR_BLUE_DEEP_BLUE);
  m_righttLineShape.setSize(sf::Vector2f(3, m_screenHeight));
  m_righttLineShape.setPosition(sf::Vector2f(m_screenWidth - 3.f, 0.f));

  m_downtLineShape.setFillColor(colors::COLOR_BLUE_DEEP_BLUE);
  m_downtLineShape.setSize(sf::Vector2f(m_screenWidth, 3));
  m_downtLineShape.setPosition(sf::Vector2f(0.f, m_screenHeight - 3.f));

  m_leftLineShape.setFillColor(colors::COLOR_BLUE_DEEP_BLUE);
  m_leftLineShape.setSize(sf::Vector2f(3, m_screenHeight));
  m_leftLineShape.setPosition(sf::Vector2f(0.f, 0.f));
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