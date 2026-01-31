#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/BaseEntity.h"
#include "Entity/Hero.h"

class Enemy : public BaseEntity
{
private:
  Hero &m_hero;

public:
  Enemy(Hero &hero);
  Enemy(Hero &hero,
        std::unique_ptr<BaseRectangle> body,
        std::unique_ptr<BaseRectangleX2> healthBar,
        std::unique_ptr<BaseCircle> shortRangeCircle,
        std::unique_ptr<BaseCircle> longRangeCircle,
        float health,
        float maxHealth,
        float speed,
        int watchRangeRadius,
        int shortRangeRadius,
        int longRangeRadius);
  ~Enemy();

  void update(sf::Time &delta) override;

  void move(sf::Time &delta);
};