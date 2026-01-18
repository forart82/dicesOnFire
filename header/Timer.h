#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

class Timer : public sf::Drawable
{
private:
  sf::RectangleShape m_backgroundShape;
  sf::RectangleShape m_progressBarShape;
  sf::Time m_elapsedTime;
  sf::Vector2f m_progressBarSize;
  float m_cooldown;
  bool m_isVertical;
  bool m_stop;

public:
  Timer(float cooldown);
  Timer(
      float cooldown,
      bool isVertical,
      sf::Vector2f position,
      sf::Vector2f size,
      float padding);

  ~Timer();

  std::function<void()> onTimeout;
  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void toggleStop();
  void setCooldown(float cooldown);

  const sf::RectangleShape &getBackground() const;
  const sf::RectangleShape &getProgressBar() const;
};