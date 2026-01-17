#include "../header/Timer.h"
#include "../header/_GLOBALS.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Timer::Timer(float cooldown)
    : Timer(
          cooldown,
          true,
          {300.f, 300.f},
          {350.f, 30.f},
          4)
{
}

Timer::Timer(
    float cooldown,
    bool vertical,
    sf::Vector2f position,
    sf::Vector2f size,
    float padding)
{
  m_cooldown = cooldown;
  m_vertical = vertical;
  m_progressBarSize = {size.x - (padding * 2), size.y - (padding * 2)};

  m_background.setPosition(position);
  m_background.setSize(size);
  m_background.setFillColor(COLOR_TIMER_BACKGROUND);

  m_progressBar.setPosition({position.x + padding, position.y + padding});
  m_progressBar.setSize(m_progressBarSize);
  m_progressBar.setFillColor(COLOR_TIMER_PROGRESSBAR);
}

Timer::~Timer() {};

void Timer::update(sf::Time &delta)
{
  if (!m_stop)
  {

    m_elapsedTime += delta;
    float seconds = m_elapsedTime.asSeconds();
    float progress = std::min(seconds / m_cooldown, 1.f);
    float progressHeight = m_progressBarSize.y;
    float progressWidth = m_progressBarSize.x;

    if (m_vertical)
    {
      progressWidth = m_progressBarSize.x - (m_progressBarSize.x * progress);
    }

    if (!m_vertical)
    {
      progressHeight = m_progressBarSize.y - (m_progressBarSize.y * progress);
    }

    m_progressBar.setSize({progressWidth, progressHeight});

    if (seconds >= m_cooldown)
    {
      if (onTimeout)
      {
        onTimeout();
      }
      m_elapsedTime = sf::Time::Zero;
    }
  }
}

void Timer::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(m_background, states);
  target.draw(m_progressBar, states);
}

const sf::RectangleShape &Timer::getBackground() const
{
  return m_background;
}

const sf::RectangleShape &Timer::getProgressBar() const
{
  return m_progressBar;
}

void Timer::toggleStop()
{
  m_stop = !m_stop;
}