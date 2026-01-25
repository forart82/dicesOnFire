#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include "Form/BaseRectangleX2.h"

class Timer : public BaseRectangleX2
{
private:
  BaseRectangleX2 m_timerMenu;
  sf::Vector2f m_progressBarSize;
  sf::Time m_elapsedTime;
  float m_cooldown;
  bool m_isVertical;
  bool m_stop;

public:
  Timer(float cooldown);
  Timer(
      BaseRectangleX2 timerMenu,
      float cooldown,
      bool isVertical);

  ~Timer();

  std::function<void()> onTimeout;
  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void toggleStop();
  void setCooldown(float cooldown);
};