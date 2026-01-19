#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include "DebugBar.h"
#include "GameText.h"
#include "Timer.h"
#include "Dice.h"
#include "Grid.h"
#include "_GLOBALS.h"
#include "DiceBox.h"
#include "DiceMenu.h"

class Game
{

private:
  // Window
  sf::RenderWindow m_window = sf::RenderWindow(sf::VideoMode({960, 600}), "Game", sf::State::Windowed);
  sf::View m_mainView = sf::View(sf::FloatRect({0, 200}, {0, 300}));

  // Time
  const sf::Time m_timePerFrame = sf::seconds(1.f / 60.f);
  sf::Time m_timeSinceLastUpdate = sf::Time::Zero;
  sf::Clock m_clock;

  bool m_isFontLoaded;

  // Entity elements
  std::unique_ptr<DebugBar> m_debugBar;
  std::unique_ptr<DiceMenu> m_diceMenu;

  std::mt19937 m_rng;

public:
  Game();
  ~Game();

  void run();
  void update(sf::Time delta);
  void draw();

  void handleMainViewRatio();
};