#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include "Entity/BaseEntity.h"
#include "Entity/Enemy.h"
#include "Entity/EnemyHelper.h"

class Enemies : public sf::Drawable
{
private:
  std::vector<std::unique_ptr<Enemy>> m_enemies;

public:
  Enemies();
  ~Enemies();

  virtual void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void addEnemy(Hero &hero);
  void removeEnemyOnDeath();

  const std::vector<std::unique_ptr<Enemy>> &getEnemies() const;
};