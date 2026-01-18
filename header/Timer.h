#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include "../header/_BaseRectangleX2.h"

class Timer : public _BaseRectangleX2
{
private:
  sf::Vector2f m_progressBarSize;
  sf::Time m_elapsedTime;
  float m_cooldown;
  bool m_isVertical;
  bool m_stop;

public:
  Timer(float cooldown);
  Timer(
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
      bool isVertical);

  ~Timer();

  std::function<void()> onTimeout;
  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void toggleStop();
  void setCooldown(float cooldown);
};