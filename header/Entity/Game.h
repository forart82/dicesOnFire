#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include "Entity/DebugBar.h"
#include "Entity/GameText.h"
#include "Entity/Timer.h"
#include "Entity/Grid.h"
#include "Entity/Dice.h"
#include "Entity/WeaponSlot.h"
#include "Entity/WeaponSlotsMenu.h"
#include "Entity/Hero.h"
#include "Entity/Enemy.h"
#include "Entity/Enemies.h"
#include "Globals/Globals.h"
#include "Hub/AttackHub.h"
#include "Hub/VertextHub.h"

class Game
{

private:
  // Window
  sf::RenderWindow m_window = sf::RenderWindow(sf::VideoMode({960, 600}), "Game", sf::State::Windowed);
  sf::View m_uiView = sf::View(sf::FloatRect({0, 200}, {globals::GLOBAL_SCREEN_WIDTH, globals::GLOBAL_SCREEN_HEIGHT}));
  sf::View m_playerView = sf::View(sf::FloatRect({0, 0}, {globals::GLOBAL_SCREEN_WIDTH, globals::GLOBAL_SCREEN_HEIGHT}));
  float m_playerZoom;

  // Time
  const sf::Time m_timePerFrame = sf::seconds(1.f / 60.f);
  sf::Time m_timeSinceLastUpdate = sf::Time::Zero;
  sf::Time m_autoDamgeTimer = sf::Time::Zero;
  sf::Clock m_clock;

  bool m_isFontLoaded;

  // Class elements
  std::unique_ptr<DebugBar> m_debugBar;
  std::unique_ptr<WeaponSlotsMenu> m_weaponSlotsMenu;
  std::unique_ptr<Hero> m_hero;
  std::unique_ptr<Grid> m_grid;
  std::unique_ptr<Enemies> m_enemies;
  std::unique_ptr<AttackHub> m_attackHub;
  std::unique_ptr<VertexHub> m_vertexHub;
  std::unique_ptr<FloorItems> m_floorItems;

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