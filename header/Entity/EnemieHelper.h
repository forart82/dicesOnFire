#pragma once

#include <SFML/Graphics.hpp>
#include "_HELPERS.h"
#include "Entity/Enemy.h"
#include "Manager/ConfigManager.h"

namespace enemyHelper
{

  inline std::unique_ptr<Enemy> CREATE_ENEMY(Hero &hero)
  {

    int health = GET_RANDOM_NUMBER_INT(50, 100);
    int maxHealth = health;
    int speed = GET_RANDOM_NUMBER_INT(100, 500);
    int watchRangeRadius = GET_RANDOM_NUMBER_INT(100, 500);
    int shortRangeRadius = GET_RANDOM_NUMBER_INT(100, 500);
    int longRangeRadius = GET_RANDOM_NUMBER_INT(shortRangeRadius, shortRangeRadius * 2);
    sf::Vector2f positionRange = sf::Vector2f(GET_RANDOM_NUMBER_INT(-1000, 1000), GET_RANDOM_NUMBER_INT(-1000, 1000));

    auto body = std::make_unique<BaseRectangle>(configManager::getRectangle("ENEMY_BODY"));
    auto healthBar = std::make_unique<BaseRectangleX2>(configManager::getRectangleX2("ENEMY_HEALTHBAR"));
    auto shortRangeCircle = std::make_unique<BaseCircle>(configManager::getCircle("ENEMY_SHORT_RANGE"));
    auto longRangeCircle = std::make_unique<BaseCircle>(configManager::getCircle("ENEMY_LONG_RANGE"));

    ADD_POSITION(body, positionRange);
    ADD_POSITION(healthBar, positionRange);
    ADD_POSITION(shortRangeCircle, positionRange);
    ADD_POSITION(longRangeCircle, positionRange);

    auto enemy = std::make_unique<Enemy>(
        hero,
        body,
        healthBar,
        shortRangeCircle,
        longRangeCircle,
        health,
        maxHealth,
        speed,
        watchRangeRadius,
        shortRangeRadius,
        longRangeRadius);

    return enemy;
  };

  template <typename T>
  inline void ADD_POSITION(std::unique_ptr<T> &component, sf::Vector2f offset)
  {
    component->addPosition(offset);
  };
}