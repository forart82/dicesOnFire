#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include "Entity/RectangleX2.h"

class Timer : public sf::Drawable
{
private:
  std::unique_ptr<RectangleX2> m_bodyBox;
  sf::Vector2f m_progressBarSize;
  sf::Time m_elapsedTime;
  float m_cooldown;
  bool m_isVertical;
  bool m_stop;

public:
  Timer(float cooldown);
  Timer(
      std::unique_ptr<RectangleX2> bodyBox,
      float cooldown,
      bool isVertical);

  ~Timer();

  std::function<void()> onTimeout;
  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void toggleStop();
  void setCooldown(float cooldown);

  const float &getCoolDown() const;
};