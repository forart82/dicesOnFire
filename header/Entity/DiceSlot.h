#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Circle.h"

class DiceSlot : public sf::Drawable
{
private:
  std::unique_ptr<Circle> m_BodyCircle;

public:
  DiceSlot();
  DiceSlot(
      std::unique_ptr<Circle> bodyCircle);
  ~DiceSlot();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};