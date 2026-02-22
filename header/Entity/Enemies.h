#pragma once

#include <SFML/Graphics.hpp>

#include "Entity/BaseEntity.h"
#include "Entity/Enemy.h"
#include "Entity/FloorItems.h"
#include "Manager/EnemyManager.h"

class Enemies : public BaseEntity, public sf::Drawable
{
private:
  std::vector<std::unique_ptr<Enemy>> m_enemies;

public:
  Enemies();
  ~Enemies();

  virtual void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void addEnemy();
  void removeEnemyOnDeath();

  const std::vector<std::unique_ptr<Enemy>> &getEnemies() const;
};