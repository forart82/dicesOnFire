#pragma once

#include "Entity/BaseCharacterBody.h"
#include "Entity/Dice.h"
#include "Entity/FloorItems.h"
#include "Entity/Hero.h"
#include "Helper/RandomHelper.h"
#include "Loader/ConfigLoader.h"
#include "Manager/DiceManager.h"

class Enemy : public BaseCharacterBody
{
private:
  bool m_houndHero;
  std::vector<std::unique_ptr<Dice>> m_dices;

public:
  Enemy();
  ~Enemy();

  void update(sf::Time &delta) override;

  void getDirectionAndMove(const sf::Time &delta);
  void prepareVertex();
  void removeHealth(int health);
  void dropItemsOnFloor();
  void houndHero();

  bool getHoundHero() const;
};