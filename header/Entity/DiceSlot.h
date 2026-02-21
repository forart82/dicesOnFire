#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Game.h"
#include "Entity/Circle.h"

class DiceSlot : public sf::Drawable
{
private:
  Game &m_game;
  std::unique_ptr<Circle> m_body;

public:
  DiceSlot(Game &game);
  ~DiceSlot();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void setBody(std::unique_ptr<Circle> body);
};