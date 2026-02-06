#pragma once

#include <SFML/Graphics.hpp>
#include "_COLORS.h"
#include "_GLOBALS.h"

class DebugWindow : public sf::Drawable
{

private:
  sf::RectangleShape m_backgroundShape;
  sf::RectangleShape m_upBlankShape;
  sf::RectangleShape m_downtBlankShape;
  sf::RectangleShape m_leftBlankShape;
  sf::RectangleShape m_righttBlankShape;

  sf::RectangleShape m_upLineShape;
  sf::RectangleShape m_downtLineShape;
  sf::RectangleShape m_leftLineShape;
  sf::RectangleShape m_righttLineShape;

public:
  DebugWindow();
  ~DebugWindow();

  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};