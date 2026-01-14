#pragma once

#include <SFML/Graphics.hpp>
#include "GameText.h"
#include "DebugWindow.h"

class DebugBar
{

private:
  GameText *m_debugText;
  DebugWindow m_debugWindow;
  bool m_isActive;

public:
  DebugBar(GameText *debugText);
  ~DebugBar();

  void update(sf::Time timePerFrame, sf::Time timeSinceLastUpdate);
  void draw(sf::RenderWindow &window);

  void toggleActive();
};