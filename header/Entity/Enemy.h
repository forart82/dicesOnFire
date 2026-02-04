#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/BaseEntity.h"
#include "Entity/Hero.h"
#include "_HELPERS.h"
#include "Vertex/VertexRectangle.h"
#include "Dice/Dice.h"
#include "Dice/DiceHelper.h"
#include "FloorItems.h"

class Enemy : public BaseEntity, public VertexRectangle
{
private:
  Hero &m_hero;
  FloorItems &m_floorItems;

  bool m_houndHero;
  std::vector<std::unique_ptr<Dice>> m_dices;

public:
  Enemy(
      Hero &hero,
      FloorItems &floorItems);
  Enemy(
      Hero &hero,
      FloorItems &floorItems,
      std::unique_ptr<BaseRectangle> body,
      std::unique_ptr<BaseRectangleX2> healthBar,
      std::unique_ptr<BaseCircle> watchRangeCircle,
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
  void prepareVertex();
  void removeHealth(int health);
  void dropItemsOnFloor();

  void houndHero();

  bool &getHoundHero();
};