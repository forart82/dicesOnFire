#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include "Game.h"
#include "DebugBar.h"
#include "Grid.h"
#include "_GLOBALS.h"
#include "ConfigManager.h"

Game::Game() : m_rng(std::random_device{}())
{
  m_debugBar = std::make_unique<DebugBar>();
  m_weaponSlotsMenu = std::make_unique<WeaponSlotsMenu>();

  m_window.setVerticalSyncEnabled(true);
  std::cout << "Game created" << std::endl;
}

Game::~Game()
{
  std::cout << "Game destroyed" << std::endl;
}

void Game::run()
{
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
        case sf::Keyboard::Scancode::W:
        case sf::Keyboard::Scancode::A:
        case sf::Keyboard::Scancode::S:
        case sf::Keyboard::Scancode::D:
        case sf::Keyboard::Scancode::Up:
        case sf::Keyboard::Scancode::Left:
        case sf::Keyboard::Scancode::Down:
        case sf::Keyboard::Scancode::Right:
          break;
        case sf::Keyboard::Scancode::R:
          break;
        case sf::Keyboard::Scancode::O:
          m_debugBar->toggleActive();
          break;
        case sf::Keyboard::Scancode::Comma:
          config::reload();
          m_weaponSlotsMenu.reset();
          m_weaponSlotsMenu = std::make_unique<WeaponSlotsMenu>();
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
  // Menu
  m_weaponSlotsMenu->update(delta);

  // Last element
  m_debugBar->update(delta);
}

void Game::draw()
{
  // Will be first
  m_window.clear();
  handleMainViewRatio();
  m_window.setView(m_mainView);

  // Will be between
  m_window.draw(*m_weaponSlotsMenu);

  // Will be last
  m_window.draw(*m_debugBar);
  m_window.display();
}

void Game::handleMainViewRatio()
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

  // m_mainView.setCenter({std::round(GLOBAL_SCREEN_WIDTH / 2), std::round(GLOBAL_SCREEN_HEIGHT / 2)});
  // m_mainView.setSize({std::round(GLOBAL_SCREEN_WIDTH), std::round(GLOBAL_SCREEN_HEIGHT)});
  // m_mainView.setViewport(sf::FloatRect({std::round(posX), std::round(posY)}, {std::round(sizeX), std::round(sizeY)}));
  m_mainView.setCenter({GLOBAL_SCREEN_WIDTH / 2, GLOBAL_SCREEN_HEIGHT / 2});
  m_mainView.setSize({GLOBAL_SCREEN_WIDTH, GLOBAL_SCREEN_HEIGHT});
  m_mainView.setViewport(sf::FloatRect({posX, posY}, {sizeX, sizeY}));
}
