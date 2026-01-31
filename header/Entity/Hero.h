#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "_ENUMS.h"
#include "Entity/BaseEntity.h"
#include "Form/BaseRectangle.h"
#include "Form/BaseRectangleX2.h"

class Hero : public BaseEntity
{
private:
  sf::Vector2f m_direction;

public:
  Hero();
  Hero(
      std::unique_ptr<BaseRectangle> body,
      std::unique_ptr<BaseRectangleX2> healthBar,
      float health,
      float maxHealth,
      float speed,
      int watchRadius);
  ~Hero();

  void update(sf::Time &delta) override;

  void move(sf::Time &delta);
};