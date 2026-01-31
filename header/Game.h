#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include "DebugBar.h"
#include "GameText.h"
#include "Timer.h"
#include "Grid.h"
#include "_GLOBALS.h"
#include "Dice/Dice.h"
#include "Weapon/WeaponSlot.h"
#include "Weapon/WeaponSlotsMenu.h"
#include "Entity/Hero.h"
#include "Entity/Enemy.h"
#include "Event/HeroEvents.h"

class Game
{

private:
  // Window
  sf::RenderWindow m_window = sf::RenderWindow(sf::VideoMode({960, 600}), "Game", sf::State::Windowed);
  sf::View m_uiView = sf::View(sf::FloatRect({0, 200}, {GLOBAL_SCREEN_WIDTH, GLOBAL_SCREEN_HEIGHT}));
  sf::View m_playerView = sf::View(sf::FloatRect({0, 0}, {GLOBAL_SCREEN_WIDTH, GLOBAL_SCREEN_HEIGHT}));
  float m_playerZoom;

  // Time
  const sf::Time m_timePerFrame = sf::seconds(1.f / 60.f);
  sf::Time m_timeSinceLastUpdate = sf::Time::Zero;
  sf::Clock m_clock;

  bool m_isFontLoaded;

  // Class elements
  std::unique_ptr<DebugBar> m_debugBar;
  std::unique_ptr<WeaponSlotsMenu> m_weaponSlotsMenu;
  std::unique_ptr<Hero> m_hero;
  std::unique_ptr<HeroEvents> m_heroEvents;
  std::unique_ptr<Grid> m_grid;
  std::unique_ptr<Enemy> m_enemy;

  std::mt19937 m_rng;

public:
  Game();
  ~Game();

  void init();

  void run();
  void update(sf::Time delta);
  void draw();

  void handleViewRatio();
  void handlePlayerZoom(std::string zoomDirection);
};