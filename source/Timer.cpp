#include "../header/Timer.h"
#include "../header/_GLOBALS.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Timer::Timer(float cooldown)
    : Timer(
          cooldown,
          {300.f, 300.f},
          {300.f, 50.f},
          COLOR_DARK_VIOLET,
          COLOR_DARK_GREEN,
          4)
{
}

Timer::Timer(
    float cooldown,
    sf::Vector2f position,
    sf::Vector2f size,
    sf::Color backgroundColor,
    sf::Color progressBarColor,
    float padding)
{
  this->m_cooldown = cooldown;
  this->m_progressBarSize = {size.x - (padding * 2), size.y - (padding * 2)};

  this->m_background.setPosition(position);
  this->m_background.setSize(size);
  this->m_background.setFillColor(backgroundColor);

  this->m_progressBar.setPosition({position.x + padding, position.y + padding});
  this->m_progressBar.setSize(this->m_progressBarSize);
  this->m_progressBar.setFillColor(progressBarColor);
}

Timer::~Timer() {};

void Timer::update(sf::Time &delta)
{
  this->m_elapsedTime += delta;
  float seconds = m_elapsedTime.asSeconds();
  float progress = std::min(seconds / this->m_cooldown, 1.f);
  float progressWidth = m_progressBarSize.x - (m_progressBarSize.x * progress);
  this->m_progressBar.setSize({progressWidth, this->m_progressBar.getSize().y});
  if (seconds >= this->m_cooldown)
  {
    m_elapsedTime = sf::Time::Zero;
  }
}

void Timer::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(this->m_background, states);
  target.draw(this->m_progressBar, states);
}

const sf::RectangleShape &Timer::getBackground() const
{
  return this->m_background;
}

const sf::RectangleShape &Timer::getProgressBar() const
{
  return this->m_progressBar;
}
