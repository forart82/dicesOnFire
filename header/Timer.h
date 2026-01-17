#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

class Timer : public sf::Drawable
{
private:
  sf::RectangleShape m_background;
  sf::RectangleShape m_progressBar;
  sf::Time m_elapsedTime;
  sf::Vector2f m_progressBarSize;
  bool m_vertical;
  float m_cooldown;
  bool m_stop;

public:
  Timer(float cooldown);
  Timer(
      float cooldown,
      bool vertical,
      sf::Vector2f position,
      sf::Vector2f size,
      float padding);

  ~Timer();

  std::function<void()> onTimeout;
  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  const sf::RectangleShape &getBackground() const;
  const sf::RectangleShape &getProgressBar() const;

  void toggleStop();
};