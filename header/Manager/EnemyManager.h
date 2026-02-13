#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Entity/Enemy.h"
#include "Entity/FloorItems.h"
#include "Helper/RandomHelper.h"
#include "Loader/ConfigLoader.h"

namespace enemyManager
{
  inline Rectangle ENEMY_BODY = configLoader::getRectangle("ENEMY_BODY");
  inline RectangleX2 ENEMY_HEALTHBAR = configLoader::getRectangleX2("ENEMY_HEALTHBAR");
  inline Circle ENEMY_WATCH_RANGE = configLoader::getCircle("ENEMY_WATCH_RANGE");
  inline Circle ENEMY_SHORT_RANGE = configLoader::getCircle("ENEMY_SHORT_RANGE");
  inline Circle ENEMY_LONG_RANGE = configLoader::getCircle("ENEMY_LONG_RANGE");

  template <typename T>
  inline void ADD_POSITION(std::unique_ptr<T> &component, sf::Vector2f offset)
  {
    component->addPosition(offset);
  };

  inline std::unique_ptr<Enemy> CREATE_ENEMY(
      Hero &hero,
      FloorItems &floorItems)
  {

    int health = randomHelper::GET_RANDOM_NUMBER_INT(50, 100);
    int maxHealth = health;
    int speed = randomHelper::GET_RANDOM_NUMBER_INT(50, 100);
    int watchRangeRadius = randomHelper::GET_RANDOM_NUMBER_INT(800, 1000);
    int shortRangeRadius = randomHelper::GET_RANDOM_NUMBER_INT(100, 350);
    int longRangeRadius = randomHelper::GET_RANDOM_NUMBER_INT(shortRangeRadius, shortRangeRadius * 2);

    int heroMinX = hero.getBody().getShape().getPosition().x - 3000;
    int heroMinY = hero.getBody().getShape().getPosition().y - 3000;
    int heroMaxX = hero.getBody().getShape().getPosition().x + 2000;
    int heroMaxY = hero.getBody().getShape().getPosition().y + 2000;
    int randomX = randomHelper::GET_RANDOM_NUMBER_INT(heroMinX, heroMaxX);
    int randomY = randomHelper::GET_RANDOM_NUMBER_INT(heroMinY, heroMaxY);

    auto bodyBox = std::make_unique<Rectangle>(ENEMY_BODY);
    auto healthBar = std::make_unique<RectangleX2>(ENEMY_HEALTHBAR);
    auto watchRangeCircle = std::make_unique<Circle>(ENEMY_WATCH_RANGE);
    auto shortRangeCircle = std::make_unique<Circle>(ENEMY_SHORT_RANGE);
    auto longRangeCircle = std::make_unique<Circle>(ENEMY_LONG_RANGE);

    watchRangeCircle->getShape().setRadius(watchRangeRadius);
    shortRangeCircle->getShape().setRadius(shortRangeRadius);
    longRangeCircle->getShape().setRadius(longRangeRadius);

    watchRangeCircle->getShape().setOrigin(
        {static_cast<float>(std::round(watchRangeRadius)),
         static_cast<float>(std::round(watchRangeRadius))});
    shortRangeCircle->getShape().setOrigin(
        {static_cast<float>(std::round(shortRangeRadius)),
         static_cast<float>(std::round(shortRangeRadius))});
    longRangeCircle->getShape().setOrigin(
        {static_cast<float>(std::round(longRangeRadius)),
         static_cast<float>(std::round(longRangeRadius))});

    bodyBox->getShape().setPosition(hero.getBody().getShape().getPosition() + sf::Vector2f(randomX, randomY));
    healthBar->getOuter().getShape().setPosition(hero.getHealthBar().getOuter().getShape().getPosition() + sf::Vector2f(randomX, randomY));
    healthBar->getInner().getShape().setPosition(hero.getHealthBar().getInner().getShape().getPosition() + sf::Vector2f(randomX, randomY));
    watchRangeCircle->getShape().setPosition(hero.getWatchRangeCircle().getShape().getPosition() + sf::Vector2f(randomX, randomY));
    shortRangeCircle->getShape().setPosition(hero.getShortRangeCircle().getShape().getPosition() + sf::Vector2f(randomX, randomY));
    longRangeCircle->getShape().setPosition(hero.getLongRangeCircle().getShape().getPosition() + sf::Vector2f(randomX, randomY));

    auto enemy = std::make_unique<Enemy>(
        hero,
        floorItems,
        std::move(bodyBox),
        std::move(healthBar),
        std::move(watchRangeCircle),
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