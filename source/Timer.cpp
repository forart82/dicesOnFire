#include "../header/Timer.h"
#include "../header/_GLOBALS.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Timer::Timer(float cooldown)
    : Timer(
          cooldown,
          true,
          {50.f, 1020.f},
          {350.f, 30.f},
          4)
{
}

Timer::Timer(
    float cooldown,
    bool isVertical,
    sf::Vector2f position,
    sf::Vector2f size,
    float padding)
    : m_stop(false), m_cooldown(cooldown), m_isVertical(isVertical)
{
  m_cooldown = cooldown;
  m_isVertical = isVertical;
  m_progressBarSize = {size.x - (padding * 2), size.y - (padding * 2)};

  m_backgroundShape.setPosition(position);
  m_backgroundShape.setSize(size);
  m_backgroundShape.setFillColor(COLOR_TIMER_BACKGROUND);

  m_progressBarShape.setPosition({position.x + padding, position.y + padding});
  m_progressBarShape.setSize(m_progressBarSize);
  m_progressBarShape.setFillColor(COLOR_TIMER_PROGRESSBAR);
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

    if (m_isVertical)
    {
      progressWidth = m_progressBarSize.x - (m_progressBarSize.x * progress);
    }

    if (!m_isVertical)
    {
      progressHeight = m_progressBarSize.y - (m_progressBarSize.y * progress);
    }

    m_progressBarShape.setSize({progressWidth, progressHeight});

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
  target.draw(m_backgroundShape, states);
  target.draw(m_progressBarShape, states);
}

void Timer::toggleStop()
{
  m_stop = !m_stop;
}

void Timer::setCooldown(float cooldown)
{
  m_cooldown = cooldown;
}

const sf::RectangleShape &Timer::getBackground() const
{
  return m_backgroundShape;
}

const sf::RectangleShape &Timer::getProgressBar() const
{
  return m_progressBarShape;
}