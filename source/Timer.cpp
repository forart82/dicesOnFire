#include <SFML/Graphics.hpp>
#include <iostream>
#include "../header/Timer.h"
#include "../header/_GLOBALS.h"
#include "../header/_BaseRectangleX2.h"

Timer::Timer(float cooldown)
    : Timer(
          sf::Vector2f(1250.f, 1020.f),
          sf::Vector2f(500.f, 100.f),
          COLOR_VIOLET_DARK_VIOLET,
          COLOR_GRAYSCALE_BLACK,
          sf::Vector2f(1250.f, 1020.f),
          sf::Vector2f(500.f, 100.f),
          COLOR_GREEN_DARK_GREEN,
          COLOR_GREEN_DARK_GREEN,
          5,
          cooldown,
          true)
{
}

Timer::Timer(
    sf::Vector2f outerPosition,
    sf::Vector2f outerSize,
    sf::Color outerFillColor,
    sf::Color outerOutlineColor,
    sf::Vector2f innerPosition,
    sf::Vector2f innerSize,
    sf::Color innerFillColor,
    sf::Color innerOutlineColor,
    float padding,
    float cooldown,
    bool isVertical)
    : _BaseRectangleX2(
          outerPosition,
          outerSize,
          outerFillColor,
          outerOutlineColor,
          innerPosition,
          innerSize,
          innerFillColor,
          innerOutlineColor,
          padding,
          true),
      m_stop(false),
      m_cooldown(cooldown),
      m_isVertical(isVertical),
      m_progressBarSize({innerSize.x - padding * 2, innerSize.y - padding * 2})

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
    }

    if (!m_isVertical)
    {
      progressHeight = m_progressBarSize.y - (m_progressBarSize.y * progress);
    }

    setInnerSize({progressWidth, progressHeight});

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
  _BaseRectangleX2::draw(target, states);
}

void Timer::toggleStop()
{
  m_stop = !m_stop;
}

void Timer::setCooldown(float cooldown)
{
  m_cooldown = cooldown;
}