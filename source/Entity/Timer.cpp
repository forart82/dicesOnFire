#include "Entity/Timer.h"

Timer::Timer(Game &game)
    : m_game(game),
      m_isStopped(false),
      m_cooldown(0),
      m_isVertical(false)
{
}

Timer::~Timer() {};

void Timer::update(sf::Time &delta)
{
  if (!m_isStopped)
  {
    m_elapsedTime += delta;
    float seconds = m_elapsedTime.asSeconds();
    float progress = std::min(seconds / m_cooldown, 1.f);
    float progressHeight = m_progressBarSize.y;
    float progressWidth = m_progressBarSize.x;

    if (m_isVertical)
    {
      progressWidth = m_progressBarSize.x - (m_progressBarSize.x * progress);
      m_body->getInner().getShape().setSize({progressWidth, progressHeight});
    }

    if (!m_isVertical)
    {
      progressHeight = m_progressBarSize.y - (m_progressBarSize.y * progress);
      m_body->getInner().getShape().setSize({progressWidth, progressHeight});
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
  target.draw(*m_body);
}

void Timer::toggleIsStopped()
{
  m_isStopped = !m_isStopped;
}

void Timer::setCooldown(const float &cooldown)
{
  m_cooldown = cooldown;
}

void Timer::setBody(std::unique_ptr<RectangleX2> body)
{
  m_body = std::move(body);
}

void Timer::setIsVertical(const bool &isVertical)
{
  m_isVertical = isVertical;
}

void Timer::setIsStopped(const bool &isStopped)
{
  m_isStopped = isStopped;
}

const float &Timer::getCoolDown() const
{
  return m_cooldown;
}

const bool &Timer::getIsStopped() const
{
  return m_isStopped;
}