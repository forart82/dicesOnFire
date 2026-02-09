#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity/GameText.h"
#include "Entity/DebugWindow.h"
#include "Entity/Hero.h"
#include "Entity/Enemies.h"
#include "Loader/TextureLoader.h"
#include "Loader/ConfigLoader.h"
#include "Loader/FontLoader.h"

class DebugBar : public sf::Drawable
{

private:
  GameText m_textGame;
  GameText m_textManager;
  GameText m_textHero;
  GameText m_textGrid;
  GameText m_textRealFps;
  DebugWindow m_debugWindow;
  bool m_isActive;

  Hero &m_hero;
  Enemies &m_enemies;

public:
  DebugBar(Hero &hero, Enemies &enemies);
  ~DebugBar();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void setRealFps(float fps);

  void toggleActive();
};