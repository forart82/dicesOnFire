#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include "Entity/RectangleX2.h"
#include "Entity/Game.h"

class Timer : public sf::Drawable
{
private:
  Game &m_game;

  std::unique_ptr<RectangleX2> m_body;
  sf::Vector2f m_progressBarSize;
  sf::Time m_elapsedTime;
  float m_cooldown;
  bool m_isVertical;
  bool m_isStopped;

public:
  Timer(Game &game);

  ~Timer();

  std::function<void()> onTimeout;
  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void toggleIsStopped();
  void setCooldown(float cooldown);
  void setBody(std::unique_ptr<RectangleX2> body);
  void setIsVertical(bool isVertical);
  void setIsStopped(bool isStopped);

  float getCoolDown() const;
  bool getIsStopped() const;
};