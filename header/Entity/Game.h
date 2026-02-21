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
#include "Entity/BluntWeapon.h"
#include "Entity/BaseWeapon.h"
#include "Entity/Inventory.h"
#include "Hub/HoverHub.h"
#include "Hub/AttackHub.h"
#include "Hub/PickUpHub.h"
#include "Hub/VertextHub.h"
#include "Hub/VertexGuiHub.h"
#include "Loader/ConfigLoader.h"
#include "Manager/WeaponManager.h"
#include "Manager/HeroManager.h"

class Game
{

private:
  // Window
  int m_screenWidth = configLoader::get<int>("GLOBAL_SCREEN_WIDTH");
  int m_screenHeight = configLoader::get<int>("GLOBAL_SCREEN_HEIGHT");
  sf::RenderWindow m_window = sf::RenderWindow(sf::VideoMode({960, 600}), "Game", sf::State::Windowed);
  sf::View m_uiView = sf::View(
      sf::FloatRect(
          {0, 200},
          sf::Vector2f(m_screenWidth, m_screenHeight)));
  sf::View m_playerView = sf::View(
      sf::FloatRect(
          {0, 0},
          sf::Vector2f(m_screenWidth, m_screenHeight)));
  float m_playerZoom;

  // Time
  const sf::Time m_timePerFrame = sf::seconds(1.f / 60.f);
  sf::Time m_timeSinceLastUpdate = sf::Time::Zero;
  sf::Time m_autoDamgeTimer = sf::Time::Zero;
  sf::Time m_FpsClock = sf::Time::Zero;
  sf::Clock m_clock;

  bool m_isFontLoaded;

  // Class elements

  // Entity
  std::unique_ptr<DebugBar> m_debugBar;
  std::unique_ptr<WeaponSlotsMenu> m_weaponSlotsMenu;
  std::unique_ptr<Hero> m_hero;
  std::unique_ptr<Grid> m_grid;
  std::unique_ptr<Enemies> m_enemies;
  std::unique_ptr<FloorItems> m_floorItems;
  std::unique_ptr<BluntWeapon> m_bluntWeapon;
  std::unique_ptr<Inventory> m_inventory;
  std::unique_ptr<ToolTip> m_toolTip;

  // Hub
  std::unique_ptr<AttackHub> m_attackHub;
  std::unique_ptr<PickUpHub> m_pickUpHub;
  std::unique_ptr<VertexHub> m_vertexHub;
  std::unique_ptr<VertexGuiHub> m_vertexGuiHub;
  std::unique_ptr<HoverHub> m_hoverHub;

  // Manager
  std::unique_ptr<HeroManager> m_heroManager;

  std::mt19937 m_rng;

public:
  Game();
  ~Game();

  void init();

  void run();
  void update(sf::Time delta);
  void draw();

  void handleViewRatio();
  void handlePlayerZoom(const std::string &zoomDirection);

  sf::RenderWindow &getWindow() const;
  Hero &getHero() const;
  Enemies &getEnemies() const;
  Inventory &getInventory() const;
  FloorItems &getFloorItems() const;
  Grid &getGrid() const;
  ToolTip &getToolTip() const;
};