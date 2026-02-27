#include "Entity/Timer.h"

Timer::Timer()
    : m_isReady(false),
      m_cooldown(0),
      m_isVertical(false)
{
  setBody(m_game->getRectangleX2Manager().create<RectangleX2>());
}

Timer::~Timer() {};

void Timer::update(const sf::Time &delta)
{
  if (!m_isReady)
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

    m_body->setInnerSize(
        sf::Vector2f(progressWidth, progressHeight));

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

void Timer::toggleIsReady()
{
  m_isReady = !m_isReady;
}

void Timer::setCooldown(float cooldown)
{
  m_cooldown = cooldown;
}

void Timer::setBody(std::unique_ptr<RectangleX2> body)
{
  m_body = std::move(body);
  m_progressBarSize = m_body->getInner().getShape().getSize();
}

void Timer::setIsVertical(bool isVertical)
{
  m_isVertical = isVertical;
}

void Timer::setIsReady(bool isReady)
{
  m_isReady = isReady;
}

float Timer::getCoolDown() const
{
  return m_cooldown;
}

bool Timer::getIsReady() const
{
  return m_isReady;
}