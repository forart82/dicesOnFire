#include "../header/Game.h"
#include "../header/DebugBar.h"
#include "../header/_GLOBALS.h"
#include "../header/Grid.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

Game::Game() : m_rng(std::random_device{}())
{
  this->m_debugText = std::make_unique<GameText>();
  this->m_debugBar = std::make_unique<DebugBar>(this->m_debugText.get());

  this->m_window.setVerticalSyncEnabled(true);
  this->m_background.setFillColor(COLOR_DEEP_CHARCOAL);
  this->m_background.setSize({GLOBAL_SCREEN_WIDTH, GLOBAL_SCREEN_HEIGHT});
  this->m_background.setPosition({0.f, 0.f});

  // Blanks
  this->m_upBlank.setFillColor(COLOR_BLUE_SHADE);
  this->m_upBlank.setSize({GLOBAL_SCREEN_WIDTH, 50});
  this->m_upBlank.setPosition({0.f, 0.f});

  this->m_righttBlank.setFillColor(COLOR_RED_SHADE);
  this->m_righttBlank.setSize({50, GLOBAL_SCREEN_HEIGHT});
  this->m_righttBlank.setPosition({GLOBAL_SCREEN_WIDTH - 50.f, 0.f});

  this->m_downtBlank.setFillColor(COLOR_YELLOW_SHADE);
  this->m_downtBlank.setSize({GLOBAL_SCREEN_WIDTH, 50});
  this->m_downtBlank.setPosition({0.f, GLOBAL_SCREEN_HEIGHT - 50.f});

  this->m_leftBlank.setFillColor(COLOR_GREEN_SHADE);
  this->m_leftBlank.setSize({50, GLOBAL_SCREEN_HEIGHT});
  this->m_leftBlank.setPosition({0.f, 0.f});

  // Lines
  this->m_upLine.setFillColor(COLOR_DEEP_BLUE);
  this->m_upLine.setSize({GLOBAL_SCREEN_WIDTH, 3});
  this->m_upLine.setPosition({0.f, 0.f});

  this->m_righttLine.setFillColor(COLOR_DEEP_BLUE);
  this->m_righttLine.setSize({3, GLOBAL_SCREEN_HEIGHT});
  this->m_righttLine.setPosition({GLOBAL_SCREEN_WIDTH - 3.f, 0.f});

  this->m_downtLine.setFillColor(COLOR_DEEP_BLUE);
  this->m_downtLine.setSize({GLOBAL_SCREEN_WIDTH, 3});
  this->m_downtLine.setPosition({0.f, GLOBAL_SCREEN_HEIGHT - 3.f});

  this->m_leftLine.setFillColor(COLOR_DEEP_BLUE);
  this->m_leftLine.setSize({3, GLOBAL_SCREEN_HEIGHT});
  this->m_leftLine.setPosition({0.f, 0.f});

  std::cout << "Game created" << sf::VideoMode().getDesktopMode().size.x << " " << sf::VideoMode().getDesktopMode().size.y << std::endl;
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
      this->update();
    }

    this->draw();
  }
}

void Game::update()
{
  // this->m_debugBar.update(this->m_timePerFrame, this->m_timeSinceLastUpdate);
  this->m_debugText->addText("Hello World !");
}

void Game::draw()
{
  this->m_window.clear();
  this->m_window.draw(this->m_background);
  this->m_window.draw(this->m_upBlank);
  this->m_window.draw(this->m_righttBlank);
  this->m_window.draw(this->m_downtBlank);
  this->m_window.draw(this->m_leftBlank);
  this->m_window.draw(this->m_upLine);
  this->m_window.draw(this->m_righttLine);
  this->m_window.draw(this->m_downtLine);
  this->m_window.draw(this->m_leftLine);

  int newWidth = this->m_window.getSize().x;
  int newHeight = newWidth * SCREEN_RATIO;

  this->m_mainView.setCenter({GLOBAL_SCREEN_WIDTH / 2, GLOBAL_SCREEN_HEIGHT / 2});
  this->m_mainView.setSize({GLOBAL_SCREEN_WIDTH, GLOBAL_SCREEN_HEIGHT});

  this->m_window.setSize({newWidth, newHeight});
  this->m_window.setView(this->m_mainView);

  m_debugBar->draw(this->m_window);
  this->m_window.display();
}
