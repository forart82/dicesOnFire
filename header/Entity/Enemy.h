#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/CharacterBody.h"
#include "Entity/Hero.h"
#include "Entity/VertexRectangle.h"
#include "Entity/Dice.h"
#include "Entity/FloorItems.h"
#include "Helper/RandomHelper.h"
#include "Manager/DiceManager.h"
#include "Loader/ConfigLoader.h"

class Enemy : public CharacterBody, public VertexRectangle
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
  ~Enemy();

  void update(sf::Time &delta) override;

  void move(sf::Time &delta);
  void prepareVertex();
  void removeHealth(int health);
  void dropItemsOnFloor();

  void houndHero();

  bool &getHoundHero();
};