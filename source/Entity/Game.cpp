#include "Entity/Game.h"

Game::Game() : m_rng(std::random_device{}())
{
  m_window.setVerticalSyncEnabled(true);
  init();
  std::cout << "Game created" << std::endl;
}

Game::~Game()
{
  std::cout << "Game destroyed" << std::endl;
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
  m_vertexHub->update(delta);
  m_vertexGuiHub->update(delta);
  m_hero->update(delta);
  m_enemies->update(delta);
  m_attackHub->update(delta);
  m_pickUpHub->update(delta);
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

void Game::init()
{
  m_playerZoom = 1;

  configLoader::reload();
  m_weaponSlotsMenu.reset();
  m_weaponSlotsMenu = std::make_unique<WeaponSlotsMenu>(
      std::make_unique<Rectangle>(configLoader::get<Rectangle>("WEAPONSLOTSMENU")));

  m_floorItems.reset();
  m_floorItems = std::make_unique<FloorItems>();
  m_inventory.reset();
  m_inventory = std::make_unique<Inventory>();

  m_hero.reset();
  m_hero = std::make_unique<Hero>(
      std::make_unique<Rectangle>(configLoader::get<Rectangle>("HERO_BODY")),
      std::make_unique<RectangleX2>(configLoader::get<RectangleX2>("HERO_HEALTHBAR")),
      std::make_unique<Circle>(configLoader::get<Circle>("HERO_WATCH_RANGE")),
      std::make_unique<Circle>(configLoader::get<Circle>("HERO_SHORT_RANGE")),
      std::make_unique<Circle>(configLoader::get<Circle>("HERO_LONG_RANGE")),
      std::make_unique<Circle>(configLoader::get<Circle>("HERO_PICK_UP_RANGE")),
      100,
      100,
      1000,
      configLoader::get<int>("PLAYER_WATCH_RADIUS"),
      25,
      50,
      50);

  m_enemies.reset();
  m_enemies = std::make_unique<Enemies>();
  for (int i = 0; i < configLoader::get<int>("MAX_ENEMIES"); i++)
  {
    m_enemies->addEnemy(*m_hero, *m_floorItems);
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
  m_bluntWeapon = weaponManager::CREATE_BLUNTWEAPON();
  m_bluntWeapon->resetLeftTop(configLoader::get<sf::Vector2f>("BLUNTWEAPON_START_POSITION"));
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
      *m_inventory);

  m_debugBar.reset();
  m_debugBar = std::make_unique<DebugBar>(*m_hero, *m_enemies);
}

void Game::handlePlayerZoom(std::string zoomDirection)
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
