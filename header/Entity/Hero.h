#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity/CharacterBody.h"
#include "Entity/Rectangle.h"
#include "Entity/RectangleX2.h"
#include "Globals/Enums.h"
#include "Loader/TextureLoader.h"

class Hero : public CharacterBody
{
private:
  sf::Vector2f m_direction;

public:
  Hero();
  Hero(
      std::unique_ptr<Rectangle> bodyBox,
      std::unique_ptr<RectangleX2> healthBar,
      std::unique_ptr<Circle> watchRangeCircle,
      std::unique_ptr<Circle> shortRangeCircle,
      std::unique_ptr<Circle> longRangeCircle,
      float health,
      float maxHealth,
      float speed,
      int watchRangeRadius,
      int shortRangeRadius,
      int longRangeRadius);
  ~Hero();

  void update(sf::Time &delta) override;

  void move(sf::Time &delta);
};