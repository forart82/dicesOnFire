#include "Entity/Timer.h"

Timer::Timer(float cooldown)
    : Timer(
          std::make_unique<RectangleX2>(),
          cooldown,
          true)
{
}

Timer::Timer(
    std::unique_ptr<RectangleX2> bodyBox,
    float cooldown,
    bool isVertical)
    : m_bodyBox(std::move(bodyBox)),
      m_stop(false),
      m_cooldown(cooldown),
      m_isVertical(isVertical),
      m_progressBarSize(m_bodyBox->getInner().getShape().getSize())
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
      m_bodyBox->getInner().getShape().setSize({progressWidth, progressHeight});
    }

    if (!m_isVertical)
    {
      progressHeight = m_progressBarSize.y - (m_progressBarSize.y * progress);
      m_bodyBox->getInner().getShape().setSize({progressWidth, progressHeight});
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
  target.draw(*m_bodyBox);
}

void Timer::toggleStop()
{
  m_stop = !m_stop;
}

void Timer::setCooldown(float cooldown)
{
  m_cooldown = cooldown;
}