#include "Entity/Game.h"

Game::Game()
    : m_rng(std::random_device{}())
{

  m_screenWidth = m_configLoader->get<int>("GLOBAL_SCREEN_WIDTH");
  m_screenHeight = m_configLoader->get<int>("GLOBAL_SCREEN_HEIGHT");
  m_uiView = sf::View(
      sf::FloatRect(
          {0, 200},
          sf::Vector2f(m_screenWidth, m_screenHeight)));
  m_playerView = sf::View(
      sf::FloatRect(
          {0, 0},
          sf::Vector2f(m_screenWidth, m_screenHeight)));

  m_window.setVerticalSyncEnabled(true);

  init();
  std::cout << "Game created" << std::endl;
}

Game::~Game()
{
  std::cout << "Game destroyed" << std::endl;
}

void Game::init()
{
  // Loader
  m_configLoader = initGameableClass<ConfigLoader>();
  m_fontLoader = initGameableClass<FontLoader>();
  m_textureLoader = initGameableClass<TextureLoader>();
  m_randomNameLoader = initGameableClass<RandomNameLoader>();

  // Entity
  m_debugBar = initGameableClass<DebugBar>();
  m_weaponSlotsMenu = initGameableClass<WeaponSlotsMenu>();
  m_hero = initGameableClass<Hero>();
  m_grid = initGameableClass<Grid>();
  m_enemies = initGameableClass<Enemies>();
  m_floorItems = initGameableClass<FloorItems>();
  m_bluntWeapon = initGameableClass<BluntWeapon>();
  m_inventory = initGameableClass<Inventory>();
  m_toolTip = initGameableClass<ToolTip>();

  // Hub
  // m_vertexHub = initGameableClass<VertexHub>();
  // m_vertexGuiHub = initGameableClass<VertexGuiHub>();

  // Manager
  m_heroManager = initGameableClass<HeroManager>();
  m_enemyManager = initGameableClass<EnemyManager>();
  m_weaponManager = initGameableClass<WeaponManager>();
  m_diceManager = initGameableClass<DiceManager>();
  m_diceSlotManager = initGameableClass<DiceSlotManager>();
  m_cellManager = initGameableClass<CellManager>();
  m_rectangleX2Manager = initGameableClass<RectangleX2Manager>();
  m_weaponSlotManager = initGameableClass<WeaponSlotManager>();
  m_weaponSlotMenuManager = initGameableClass<WeaponSlotMenuManager>();

  m_playerZoom = 1;

  m_configLoader->reload();
  m_fontLoader->reload();
  m_randomNameLoader->reload();

  m_weaponSlotsMenu->setBody(std::make_unique<Rectangle>(m_configLoader->get<Rectangle>("WEAPONSLOTSMENU")));

  m_hero = m_heroManager->createHero();
  for (int i = 0; i < m_configLoader->get<int>("MAX_ENEMIES"); i++)
  {
    m_enemies->addEnemy();
  }

  m_bluntWeapon = m_weaponManager->createBluntWeapon();
  m_bluntWeapon->setVertexBodyPosition(m_configLoader->get<sf::Vector2f>("BLUNTWEAPON_START_POSITION"));
  m_floorItems->addWeapon(std::move(m_bluntWeapon));

  m_vertexHub.reset();
  m_vertexHub = std::make_unique<VertexHub>(
      *m_grid,
      *m_floorItems,
      *m_hero,
      *m_enemies);

  m_vertexGuiHub = std::make_unique<VertexGuiHub>(
      *m_inventory,
      *m_toolTip);
}

template <typename T>
std::unique_ptr<T> Game::initGameableClass()
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

// MARK: Entity
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

// MARK: Loader
ConfigLoader &Game::getConfigLoader() const
{
  return *m_configLoader;
}

FontLoader &Game::getFontLoader() const
{
  return *m_fontLoader;
}

TextureLoader &Game::getTextureLoader() const
{
  return *m_textureLoader;
}

RandomNameLoader &Game::getRandomNameLoader() const
{
  return *m_randomNameLoader;
}

// MARK: Manager
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

WeaponSlotMenuManager &Game::getWeaponSlotMenuManager() const
{
  return *m_weaponSlotMenuManager;
}