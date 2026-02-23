#include "Entity/Game.h"

Game::Game()
    : m_rng(std::random_device{}())
{
  m_debugBar = initManager<DebugBar>();
  m_weaponSlotsMenu = initManager<WeaponSlotsMenu>();
  m_hero = initManager<Hero>();
  m_grid = initManager<Grid>();
  m_enemies = initManager<Enemies>();
  m_floorItems = initManager<FloorItems>();
  m_bluntWeapon = initManager<BluntWeapon>();
  m_inventory = initManager<Inventory>();
  m_toolTip = initManager<ToolTip>();
  m_attackHub = initManager<AttackHub>();
  m_pickUpHub = initManager<PickUpHub>();
  m_vertexHub = initManager<VertexHub>();
  m_vertexGuiHub = initManager<VertexGuiHub>();
  m_hoverHub = initManager<HoverHub>();
  m_configLoader = initManager<ConfigLoader>();
  m_fontLoader = initManager<FontLoader>();
  m_enemyManager = initManager<EnemyManager>();
  m_heroManager = initManager<HeroManager>();
  m_weaponManager = initManager<WeaponManager>();
  m_diceManager = initManager<DiceManager>();
  m_diceSlotManager = initManager<DiceSlotManager>();
  m_cellManager = initManager<CellManager>();
  m_rectangleX2Manager = initManager<RectangleX2Manager>();
  m_weaponSlotManager = initManager<WeaponSlotManager>();

  int m_screenWidth = m_configLoader->get<int>("GLOBAL_SCREEN_WIDTH");
  int m_screenHeight = m_configLoader->get<int>("GLOBAL_SCREEN_HEIGHT");
  m_uiView = sf::View(
      sf::FloatRect(
          {0, 200},
          sf::Vector2f(m_screenWidth, m_screenHeight)));
  m_playerView = sf::View(
      sf::FloatRect(
          {0, 0},
          sf::Vector2f(m_screenWidth, m_screenHeight)));

  m_window.setVerticalSyncEnabled(true);
  m_hero = std::make_unique<Hero>(this);
  m_enemies = std::make_unique<Enemies>(this);
  m_inventory = std::make_unique<Inventory>(this);
  m_floorItems = std::make_unique<FloorItems>(this);
  m_grid = std::make_unique<Grid>(this);
  m_toolTip = std::make_unique<ToolTip>(this);

  m_heroManager = std::make_unique<HeroManager>(this);

  init();
  std::cout << "Game created" << std::endl;
}

Game::~Game()
{
  std::cout << "Game destroyed" << std::endl;
}

void Game::init()
{
  m_playerZoom = 1;

  m_configLoader->reload();
  randomNameLoader::reload();
  m_weaponSlotsMenu.reset();
  m_weaponSlotsMenu = std::make_unique<WeaponSlotsMenu>(this);
  m_weaponSlotsMenu->setBody(std::make_unique<Rectangle>(m_configLoader->get<Rectangle>("WEAPONSLOTSMENU")));

  m_floorItems.reset();
  m_floorItems = std::make_unique<FloorItems>(this);
  m_inventory.reset();
  m_inventory = std::make_unique<Inventory>(this);
  m_toolTip.reset();
  m_toolTip = std::make_unique<ToolTip>(this);

  m_hero.reset();
  m_hero = m_heroManager->createHero();

  m_enemies.reset();
  m_enemies = std::make_unique<Enemies>();
  for (int i = 0; i < m_configLoader->get<int>("MAX_ENEMIES"); i++)
  {
    m_enemies->addEnemy();
  }

  m_attackHub.reset();
  m_attackHub = std::make_unique<AttackHub>(
      *m_hero,
      *m_enemies);
  m_pickUpHub.reset();
  m_pickUpHub = std::make_unique<PickUpHub>(
      *m_hero,
      *m_floorItems,
      *m_inventory);

  m_bluntWeapon.reset();
  m_bluntWeapon = m_weaponManager->createBluntWeapon();
  m_bluntWeapon->setVertexBodyPosition(m_configLoader->get<sf::Vector2f>("BLUNTWEAPON_START_POSITION"));
  m_floorItems->addWeapon(std::move(m_bluntWeapon));

  m_grid.reset();
  m_grid = std::make_unique<Grid>();
  m_vertexHub.reset();
  m_vertexHub = std::make_unique<VertexHub>(
      *m_grid,
      *m_floorItems,
      *m_hero,
      *m_enemies);

  m_vertexGuiHub.reset();
  m_vertexGuiHub = std::make_unique<VertexGuiHub>(
      *m_inventory,
      *m_toolTip);

  m_hoverHub.reset();
  m_hoverHub = std::make_unique<HoverHub>(
      m_window,
      m_playerView,
      m_uiView,
      *m_toolTip,
      *m_floorItems,
      *m_inventory);

  m_debugBar.reset();
  m_debugBar = std::make_unique<DebugBar>(
      m_window,
      *m_hero,
      *m_enemies);
}
template <typename T>
std::unique_ptr<T> initManager()
{
  auto manager = std::make_unique<T>();
  manager->setGame(this);
  return manager;
}

void Game::run()
{
  float z = 1;
  while (m_window.isOpen())
  {
    while (auto event = m_window.pollEvent())
    {
      if (event->is<sf::Event::Closed>())
      {
        m_window.close();
      }

      if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
      {

        switch (keyPressed->scancode)
        {
        case sf::Keyboard::Scancode::I:
          m_inventory->toggleInventory();
          break;
        case sf::Keyboard::Scancode::O:
          m_debugBar->toggleActive();
          break;
        case sf::Keyboard::Scancode::R:
          break;
        case sf::Keyboard::Scancode::Comma:
          init();
          break;
        case sf::Keyboard::Scancode::F5:
        case sf::Keyboard::Scancode::Escape:
          m_window.close();
          break;
        case sf::Keyboard::Scancode::PageUp:
          handlePlayerZoom("up");
          break;
        case sf::Keyboard::Scancode::PageDown:
          handlePlayerZoom("down");
          break;
        default:
          break;
        }
      }
      if (event->is<sf::Event::MouseButtonPressed>())
      {
      }
      if (const auto *mouseWheelScrolled = event->getIf<sf::Event::MouseWheelScrolled>())
      {
        if (mouseWheelScrolled->delta > 0)
        {
          handlePlayerZoom("up");
        }
        else
        {
          handlePlayerZoom("down");
        }
      }
    }

    sf::Time realDelta = m_clock.restart();
    m_timeSinceLastUpdate += realDelta;
    m_FpsClock += realDelta;
    if (m_FpsClock.asSeconds() >= 1.0f)
    {
      m_debugBar->setRealFps(1.0f / realDelta.asSeconds());
      m_FpsClock = sf::Time::Zero;
    }
    while (m_timeSinceLastUpdate >= m_timePerFrame)
    {
      m_timeSinceLastUpdate -= m_timePerFrame;
      update(m_timePerFrame);
    }
    draw();
  }
}

void Game::update(sf::Time delta)
{

  m_autoDamgeTimer += delta;

  if (m_autoDamgeTimer.asSeconds() > 0.1f)
  {
    for (auto &enemy : m_enemies->getEnemies())
    {
      enemy->removeHealth(1);
    }
    m_autoDamgeTimer = sf::Time::Zero;
  }
  // Elements
  m_hero->update(delta);
  m_enemies->update(delta);
  m_attackHub->update(delta);
  m_pickUpHub->update(delta);
  m_hoverHub->update(delta);
  m_vertexHub->update(delta);
  m_vertexGuiHub->update(delta);
  m_weaponSlotsMenu->update(delta);

  // Last element
  m_debugBar->update(delta);
}

void Game::draw()
{
  // Will be first
  m_window.clear();
  handleViewRatio();

  // Will be between
  m_window.setView(m_playerView);
  m_window.draw(*m_vertexHub);
  m_window.draw(*m_hero);
  m_window.draw(*m_enemies);

  m_window.setView(m_uiView);
  m_window.draw(*m_weaponSlotsMenu);
  m_window.draw(*m_vertexGuiHub);
  m_window.draw(*m_toolTip);

  // Will be last
  m_window.draw(*m_debugBar);
  m_window.display();
}

void Game::handleViewRatio()
{

  float targetRatio = (float)m_screenWidth / m_screenHeight;
  float windowRatio = (float)m_window.getSize().x / (float)m_window.getSize().y;

  float sizeX = 1.f;
  float sizeY = 1.f;
  float posX = 0.f;
  float posY = 0.f;

  if (windowRatio > targetRatio)
  {
    sizeX = targetRatio / windowRatio;
    posX = (1.f - sizeX) / 2.f;
  }
  else
  {
    sizeY = windowRatio / targetRatio;
    posY = (1.f - sizeY) / 2.f;
  }
  m_playerView.setCenter(m_hero->getBody().getShape().getPosition());
  m_playerView.setSize(sf::Vector2f(m_screenWidth, m_screenHeight));
  m_playerView.zoom(m_playerZoom);
  m_playerView.setViewport(sf::FloatRect({posX, posY}, {sizeX, sizeY}));
  m_uiView.setCenter(sf::Vector2f(m_screenWidth / 2, m_screenHeight / 2));
  m_uiView.setSize(sf::Vector2f(m_screenWidth, m_screenHeight));
  m_uiView.setViewport(sf::FloatRect({posX, posY}, {sizeX, sizeY}));
}

void Game::handlePlayerZoom(const std::string &zoomDirection)
{
  if (m_playerZoom > 0.1f)
  {
    if (zoomDirection == "up")
    {
      m_playerZoom -= 0.1f;
    }
  }
  if (m_playerZoom < 2.f)
  {
    if (zoomDirection == "down")
    {
      m_playerZoom += 0.1f;
    }
  }
}

sf::RenderWindow &Game::getWindow()
{
  return m_window;
}

Hero &Game::getHero() const
{
  return *m_hero;
}

Enemies &Game::getEnemies() const
{
  return *m_enemies;
}

Inventory &Game::getInventory() const
{
  return *m_inventory;
}
FloorItems &Game::getFloorItems() const
{
  return *m_floorItems;
}
Grid &Game::getGrid() const
{
  return *m_grid;
}
ToolTip &Game::getToolTip() const
{
  return *m_toolTip;
}

ConfigLoader &Game::getConfigLoader() const
{
  return *m_configLoader;
}

FontLoader &Game::getFontLoader() const
{
  return *m_fontLoader;
}

EnemyManager &Game::getEnemyManager() const
{
  return *m_enemyManager;
}

HeroManager &Game::getHeroManager() const
{
  return *m_heroManager;
}
WeaponManager &Game::getWeaponManager() const
{
  return *m_weaponManager;
}

DiceManager &Game::getDiceManager() const
{
  return *m_diceManager;
}
TimerManager &Game::getTimerManager() const
{
  return *m_timerManager;
}

DiceSlotManager &Game::getDiceSlotManager() const
{
  return *m_diceSlotManager;
}

CellManager &Game::getCellManager() const
{
  return *m_cellManager;
}

RectangleX2Manager &Game::getRectangleX2Manager() const
{
  return *m_rectangleX2Manager;
}

WeaponSlotManager &Game::getWeaponSlotManager() const
{
  return *m_weaponSlotManager;
}