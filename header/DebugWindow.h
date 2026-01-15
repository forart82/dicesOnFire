#pragma once

#include <SFML/Graphics.hpp>

class DebugWindow : public sf::Drawable
{

private:
  sf::RectangleShape m_background;
  sf::RectangleShape m_upBlank;
  sf::RectangleShape m_downtBlank;
  sf::RectangleShape m_leftBlank;
  sf::RectangleShape m_righttBlank;

  sf::RectangleShape m_upLine;
  sf::RectangleShape m_downtLine;
  sf::RectangleShape m_leftLine;
  sf::RectangleShape m_righttLine;

public:
  DebugWindow();
  ~DebugWindow();

  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};