#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/BaseEntity.h"

class Hero : public BaseEntity
{
private:
public:
  Hero();
  Hero(
      std::unique_ptr<BaseRectangle> body,
      std::unique_ptr<BaseRectangleX2> healthBar,
      float health,
      float maxHealth,
      float speed);
  ~Hero();
};