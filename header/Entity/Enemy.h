#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/BaseCharacterBody.h"
#include "Entity/Hero.h"
#include "Entity/Dice.h"
#include "Entity/FloorItems.h"
#include "Helper/RandomHelper.h"
#include "Manager/DiceManager.h"
#include "Loader/ConfigLoader.h"

class Enemy : public BaseCharacterBody
{
private:
  Game &m_game;
  Hero &m_hero;
  FloorItems &m_floorItems;

  bool m_houndHero;
  std::vector<std::unique_ptr<Dice>> m_dices;

public:
  Enemy(Game &game);
  ~Enemy();

  void update(sf::Time &delta) override;

  void move(const sf::Time &delta);
  void prepareVertex();
  void removeHealth(int health);
  void dropItemsOnFloor();
  void houndHero();

  bool getHoundHero() const;
};