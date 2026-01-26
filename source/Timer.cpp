#include <SFML/Graphics.hpp>
#include <iostream>
#include "Timer.h"
#include "ConfigManager.h"
#include "Form/BaseRectangle.h"
#include "Form/BaseRectangleX2.h"
#include "_GLOBALS.h"
#include "_COLORS.h"

Timer::Timer(float cooldown)
    : Timer(
          BaseRectangleX2(
              BaseRectangle(
                  sf::Vector2f(1250.f, 1020.f),
                  sf::Vector2f(500.f, 100.f),
                  1,
                  true,
                  colors::COLOR_TIMER_PROGRESSBAR,
                  colors::COLOR_GRAYSCALE_BLACK),
              BaseRectangle(
                  sf::Vector2f(1250.f, 1020.f),
                  sf::Vector2f(500.f, 100.f),
                  1,
                  true,
                  colors::COLOR_TIMER_PROGRESSBAR,
                  colors::COLOR_GRAYSCALE_BLACK)),
          cooldown,
          true)
{
}

Timer::Timer(
    BaseRectangleX2 timerMenu,
    float cooldown,
    bool isVertical)
    : BaseRectangleX2(timerMenu),
      m_stop(false),
      m_cooldown(cooldown),
      m_isVertical(isVertical),
      m_progressBarSize(timerMenu.getInner().getSize())

{
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
      this->getInner().setSize({progressWidth, progressHeight});
    }

    if (!m_isVertical)
    {
      progressHeight = m_progressBarSize.y - (m_progressBarSize.y * progress);
      this->getInner().setSize({progressWidth, progressHeight});
    }

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
  BaseRectangleX2::draw(target, states);
}

void Timer::toggleStop()
{
  m_stop = !m_stop;
}

void Timer::setCooldown(float cooldown)
{
  m_cooldown = cooldown;
}