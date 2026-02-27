#pragma once

#include "Ability/Gameable.h"
#include "Globals/Colors.h"
#include "Loader/ConfigLoader.h"

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

  int m_screenWidth;
  int m_screenHeight;

public:
  DebugWindow(int screenWidht, int screenHeight);
  ~DebugWindow();

  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};