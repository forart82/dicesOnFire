#pragma once

#include <functional>

#include "Entity/BaseEntity.h"
#include "Entity/RectangleX2.h"

class Timer : public BaseEntity, public sf::Drawable
{
private:
  std::unique_ptr<RectangleX2> m_body;
  sf::Vector2f m_progressBarSize;
  sf::Time m_elapsedTime;
  float m_cooldown;
  bool m_isVertical;
  bool m_isReady;

public:
  Timer();
  ~Timer();

  std::function<void()> onTimeout;
  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void toggleIsReady();
  void setCooldown(float cooldown);
  void setBody(std::unique_ptr<RectangleX2> body);
  void setIsVertical(bool isVertical);
  void setIsReady(bool isReady);

  float getCoolDown() const;
  bool getIsReady() const;
};