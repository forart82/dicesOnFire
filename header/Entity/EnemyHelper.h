#pragma once

#include <SFML/Graphics.hpp>
#include "_HELPERS.h"
#include "Entity/Enemy.h"
#include "Manager/ConfigManager.h"

namespace enemyHelper
{

  template <typename T>
  inline void ADD_POSITION(std::unique_ptr<T> &component, sf::Vector2f offset)
  {
    component->addPosition(offset);
  };

  inline std::unique_ptr<Enemy> CREATE_ENEMY(Hero &hero)
  {

    int health = helper::GET_RANDOM_NUMBER_INT(50, 100);
    int maxHealth = health;
    int speed = helper::GET_RANDOM_NUMBER_INT(100, 500);
    int watchRangeRadius = helper::GET_RANDOM_NUMBER_INT(100, 500);
    int shortRangeRadius = helper::GET_RANDOM_NUMBER_INT(100, 500);
    int longRangeRadius = helper::GET_RANDOM_NUMBER_INT(shortRangeRadius, shortRangeRadius * 2);

    int heroMinX = hero.getBody().getShape().getPosition().x - 3000;
    int heroMinY = hero.getBody().getShape().getPosition().y - 3000;
    int heroMaxX = hero.getBody().getShape().getPosition().x + 2000;
    int heroMaxY = hero.getBody().getShape().getPosition().y + 2000;
    int randomX = helper::GET_RANDOM_NUMBER_INT(heroMinX, heroMaxX);
    int randomY = helper::GET_RANDOM_NUMBER_INT(heroMinY, heroMaxY);

    auto body = std::make_unique<BaseRectangle>(configManager::getRectangle("ENEMY_BODY"));
    auto healthBar = std::make_unique<BaseRectangleX2>(configManager::getRectangleX2("ENEMY_HEALTHBAR"));
    auto shortRangeCircle = std::make_unique<BaseCircle>(configManager::getCircle("ENEMY_SHORT_RANGE"));
    auto longRangeCircle = std::make_unique<BaseCircle>(configManager::getCircle("ENEMY_LONG_RANGE"));

    body->getShape().setPosition(hero.getBody().getShape().getPosition() + sf::Vector2f(randomX, randomY));
    healthBar->getOuter().getShape().setPosition(hero.getHealthBar().getOuter().getShape().getPosition() + sf::Vector2f(randomX, randomY));
    healthBar->getInner().getShape().setPosition(hero.getHealthBar().getInner().getShape().getPosition() + sf::Vector2f(randomX, randomY));
    shortRangeCircle->getShape().setPosition(hero.getShortRangeCircle().getShape().getPosition() + sf::Vector2f(randomX, randomY));
    longRangeCircle->getShape().setPosition(hero.getLongRangeCircle().getShape().getPosition() + sf::Vector2f(randomX, randomY));

    auto enemy = std::make_unique<Enemy>(
        hero,
        std::move(body),
        std::move(healthBar),
        std::move(shortRangeCircle),
        std::move(longRangeCircle),
        health,
        maxHealth,
        speed,
        watchRangeRadius,
        shortRangeRadius,
        longRangeRadius);

    return enemy;
  };
}