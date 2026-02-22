#pragma once

#include "Entity/BaseCharacterBody.h"

class Hero : public BaseCharacterBody
{
private:
  sf::Vector2f m_direction;

public:
  Hero();
  ~Hero();

  void update(sf::Time &delta) override;

  void move(const sf::Time &delta);
};