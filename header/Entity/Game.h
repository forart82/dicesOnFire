#pragma once

#include <algorithm>
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <random>
#include <random>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <vector>

#include "Entity/BaseWeapon.h"
#include "Entity/BluntWeapon.h"
#include "Entity/DebugBar.h"
#include "Entity/Dice.h"
#include "Entity/Enemies.h"
#include "Entity/Enemy.h"
#include "Entity/GameText.h"
#include "Entity/Grid.h"
#include "Entity/Hero.h"
#include "Entity/Inventory.h"
#include "Entity/Timer.h"
#include "Entity/WeaponSlot.h"
#include "Entity/WeaponSlotsMenu.h"

#include "Hub/AttackHub.h"
#include "Hub/HoverHub.h"
#include "Hub/PickUpHub.h"
#include "Hub/VertexGuiHub.h"
#include "Hub/VertextHub.h"

#include "Loader/ConfigLoader.h"
#include "Loader/FontLoader.h"
#include "Loader/TextureLoader.h"
#include "Loader/RandomNameLoader.h"

#include "Manager/DiceManager.h"
#include "Manager/EnemyManager.h"
#include "Manager/HeroManager.h"
#include "Manager/WeaponManager.h"
#include "Manager/TimerManager.h"
#include "Manager/DiceSlotManager.h"
#include "Manager/CellManager.h"
#include "Manager/RectangleX2Manager.h"
#include "Manager/WeaponSlotManager.h"
#include "Manager/WeaponSlotMenuManager.h"

class Game
{

private:
  // Window
  int m_screenWidth;
  int m_screenHeight;
  sf::RenderWindow m_window = sf::RenderWindow(sf::VideoMode({960, 600}), "Game", sf::State::Windowed);
  sf::View m_uiView;
  sf::View m_playerView;
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

  // Loader
  std::unique_ptr<ConfigLoader> m_configLoader;
  std::unique_ptr<FontLoader> m_fontLoader;
  std::unique_ptr<TextureLoader> m_textureLoader;
  std::unique_ptr<RandomNameLoader> m_randomNameLoader;

  // Manager
  std::unique_ptr<EnemyManager> m_enemyManager;
  std::unique_ptr<HeroManager> m_heroManager;
  std::unique_ptr<WeaponManager> m_weaponManager;
  std::unique_ptr<DiceManager> m_diceManager;
  std::unique_ptr<TimerManager> m_timerManager;
  std::unique_ptr<DiceSlotManager> m_diceSlotManager;
  std::unique_ptr<CellManager> m_cellManager;
  std::unique_ptr<RectangleX2Manager> m_rectangleX2Manager;
  std::unique_ptr<WeaponSlotManager> m_weaponSlotManager;
  std::unique_ptr<WeaponSlotMenuManager> m_weaponSlotMenuManager;

  std::mt19937 m_rng;

public:
  Game();
  ~Game();

  void init();
  template <typename T>
  std::unique_ptr<T> initGameableClass();

  void run();
  void update(sf::Time delta);
  void draw();

  void handleViewRatio();
  void handlePlayerZoom(const std::string &zoomDirection);

  sf::RenderWindow &getWindow();

  // Entity
  Hero &getHero() const;
  Enemies &getEnemies() const;
  Inventory &getInventory() const;
  FloorItems &getFloorItems() const;
  Grid &getGrid() const;
  ToolTip &getToolTip() const;

  // Loader
  ConfigLoader &getConfigLoader() const;
  FontLoader &getFontLoader() const;
  TextureLoader &getTextureLoader() const;
  RandomNameLoader &getRandomNameLoader() const;

  // Manager
  EnemyManager &getEnemyManager() const;
  HeroManager &getHeroManager() const;
  WeaponManager &getWeaponManager() const;
  DiceManager &getDiceManager() const;
  TimerManager &getTimerManager() const;
  DiceSlotManager &getDiceSlotManager() const;
  CellManager &getCellManager() const;
  RectangleX2Manager &getRectangleX2Manager() const;
  WeaponSlotManager &getWeaponSlotManager() const;
  WeaponSlotMenuManager &getWeaponSlotMenuManager() const;
};