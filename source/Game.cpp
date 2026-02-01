#include "Game.h"

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
        case sf::Keyboard::Scancode::F5:
        case sf::Keyboard::Scancode::Escape:
          m_window.close();
          break;
        case sf::Keyboard::Scancode::R:
          break;
        case sf::Keyboard::Scancode::O:
          m_debugBar->toggleActive();
          break;
        case sf::Keyboard::Scancode::Comma:
          init();
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
    }

    m_timeSinceLastUpdate += m_clock.restart();
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
  // Elements
  m_grid->update(delta);
  m_hero->update(delta);
  m_enemies->update(delta);
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
  m_window.draw(*m_grid);
  m_window.draw(*m_hero);

  m_window.draw(*m_enemies);

  m_window.setView(m_uiView);
  m_window.draw(*m_weaponSlotsMenu);

  // Will be last
  m_window.draw(*m_debugBar);
  m_window.display();
}

void Game::handleViewRatio()
{

  float targetRatio = (float)GLOBAL_SCREEN_WIDTH / (float)GLOBAL_SCREEN_HEIGHT;
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
  m_playerView.setSize({GLOBAL_SCREEN_WIDTH, GLOBAL_SCREEN_HEIGHT});
  m_playerView.zoom(m_playerZoom);
  m_playerView.setViewport(sf::FloatRect({posX, posY}, {sizeX, sizeY}));
  m_uiView.setCenter({GLOBAL_SCREEN_WIDTH / 2, GLOBAL_SCREEN_HEIGHT / 2});
  m_uiView.setSize({GLOBAL_SCREEN_WIDTH, GLOBAL_SCREEN_HEIGHT});
  m_uiView.setViewport(sf::FloatRect({posX, posY}, {sizeX, sizeY}));
}

void Game::init()
{
  m_playerZoom = 1;

  configManager::reload();
  m_weaponSlotsMenu.reset();
  m_weaponSlotsMenu = std::make_unique<WeaponSlotsMenu>();
  m_hero.reset();
  m_hero = std::make_unique<Hero>(
      std::make_unique<BaseRectangle>(configManager::getRectangle("HERO_BODY")),
      std::make_unique<BaseRectangleX2>(configManager::getRectangleX2("HERO_HEALTHBAR")),
      std::make_unique<BaseCircle>(configManager::getCircle("HERO_SHORT_RANGE")),
      std::make_unique<BaseCircle>(configManager::getCircle("HERO_LONG_RANGE")),
      100,
      100,
      1000,
      PLAYER_WATCH_RADIUS,
      25,
      50);

  m_heroEvents.reset();
  m_heroEvents = std::make_unique<HeroEvents>(*m_hero);

  m_enemies.reset();
  m_enemies = std::make_unique<Enemies>();
  m_enemies->addEnemy(*m_hero);
  // m_enemy = std::make_unique<Enemy>(
  //     *m_hero, std::make_unique<BaseRectangle>(configManager::getRectangle("ENEMY_BODY")),
  //     std::make_unique<BaseRectangleX2>(configManager::getRectangleX2("ENEMY_HEALTHBAR")),
  //     std::make_unique<BaseCircle>(configManager::getCircle("ENEMY_SHORT_RANGE")),
  //     std::make_unique<BaseCircle>(configManager::getCircle("ENEMY_LONG_RANGE")),
  //     100,
  //     100,
  //     200,
  //     PLAYER_WATCH_RADIUS,
  //     25,
  //     50);

  m_grid.reset();
  m_grid = std::make_unique<Grid>(*m_hero);

  m_debugBar.reset();
  m_debugBar = std::make_unique<DebugBar>(*m_hero, *m_grid);
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
