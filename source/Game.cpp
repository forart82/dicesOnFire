#include "../header/Game.h"
#include "../header/DebugBar.h"
#include "../header/_GLOBALS.h"
#include "../header/Grid.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

Game::Game() : m_rng(std::random_device{}())
{
  this->m_debugBar = std::make_unique<DebugBar>();
  this->m_timer = std::make_unique<Timer>(2);

  this->m_window.setVerticalSyncEnabled(true);
  std::cout << "Game created" << std::endl;
}

Game::~Game()
{
  std::cout << "Game destroyed" << std::endl;
}

void Game::run()
{
  while (this->m_window.isOpen())
  {
    while (auto event = this->m_window.pollEvent())
    {
      if (event->is<sf::Event::Closed>())
      {
        this->m_window.close();
      }
      if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
      {
        switch (keyPressed->scancode)
        {
        case sf::Keyboard::Scancode::F5:
        case sf::Keyboard::Scancode::Escape:
          this->m_window.close();
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
          this->m_debugBar->toggleActive();
          break;
        default:
          break;
        }
      }
      if (event->is<sf::Event::MouseButtonPressed>())
      {
      }
    }

    this->m_timeSinceLastUpdate += this->m_clock.restart();
    while (this->m_timeSinceLastUpdate >= this->m_timePerFrame)
    {
      this->m_timeSinceLastUpdate -= this->m_timePerFrame;
      this->update(this->m_timePerFrame);
    }
    this->draw();
  }
}

void Game::update(sf::Time delta)
{
  this->m_timer->update(delta);
  this->m_debugBar->update(delta);
}

void Game::draw()
{
  // Will be first
  this->m_window.clear();
  this->handleMainViewRatio();
  this->m_window.setView(this->m_mainView);

  // Will be between
  this->m_window.draw(*this->m_timer);

  // Will be last
  this->m_window.draw(*this->m_debugBar);
  this->m_window.display();
}

void Game::handleMainViewRatio()
{
  this->m_mainView.setCenter({GLOBAL_SCREEN_WIDTH / 2, GLOBAL_SCREEN_HEIGHT / 2});
  this->m_mainView.setSize({GLOBAL_SCREEN_WIDTH, GLOBAL_SCREEN_HEIGHT});

  float targetRatio = (float)GLOBAL_SCREEN_WIDTH / (float)GLOBAL_SCREEN_HEIGHT;
  float windowRatio = (float)this->m_window.getSize().x / (float)this->m_window.getSize().y;

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
  this->m_mainView.setViewport(sf::FloatRect({posX, posY}, {sizeX, sizeY}));
}
