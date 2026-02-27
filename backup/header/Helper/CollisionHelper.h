#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Circle.h"

namespace collisionHelper
{

  inline bool insideRadar(const sf::Vector2f &targetPosition, Circle &radar)
  {

    float radius = radar.getShape().getRadius();
    sf::Vector2f center = radar.getShape().getPosition();

    float dx = targetPosition.x - center.x;
    float dy = targetPosition.y - center.y;

    return (dx * dx + dy * dy) <= (radius * radius);
  }
}