#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/ToolTip.h"
#include "Entity/Rectangle.h"

class Hoverable
{
private:
  ToolTip *m_hoverableToolTip = nullptr;
  sf::View *m_hoverablePlayerView = nullptr;
  sf::View *m_hoverableUiView = nullptr;
  sf::RenderWindow *m_hoverableWindow = nullptr;

protected:
  sf::Time m_hoverableElapsedTime;
  float m_hoverableShowUpTime;

public:
  Hoverable();
  virtual ~Hoverable() = default;

  void bind(
      ToolTip *hoverableToolTip,
      sf::View *hoverablePlayerView,
      sf::View *hoverableUiView,
      sf::RenderWindow *hoverableWindow);

  void update(const sf::Time &delta);

  void checkHoverOverItem();
  void resetToolTip(const sf::Time &delta);

  virtual const sf::FloatRect &getGlobalBounds() const = 0;

  virtual std::string setHoverableShowUpTime(float hoverableShowUpTime) const = 0;
  virtual std::string getName() const = 0;
  virtual std::string getStats() const = 0;
};