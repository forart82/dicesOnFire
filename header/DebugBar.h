#pragma once

#include <SFML/Graphics.hpp>
#include "GameText.h"

class DebugBar
{

private:
  GameText *m_debugText;
  bool m_isActive;

public:
  DebugBar(GameText *debugText);
  ~DebugBar();

  void update(sf::Time timePerFrame, sf::Time timeSinceLastUpdate);
  void draw(sf::RenderWindow &window);

  void toggleActive();
};