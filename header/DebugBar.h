#pragma once

#include <SFML/Graphics.hpp>
#include "GameText.h"
#include "DebugWindow.h"

class DebugBar : public sf::Drawable
{

private:
  GameText m_debugText;
  DebugWindow m_debugWindow;
  bool m_isActive;

public:
  DebugBar();
  ~DebugBar();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void toggleActive();

  GameText getDebugText();
};