#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include "Entity/BaseEntity.h"
#include "Entity/Enemy.h"
#include "Entity/EnemyHelper.h"
#include "Vertex/VertexRectangle.h"
#include "FloorItems.h"

class Enemies : public sf::Drawable
{
private:
  std::vector<std::unique_ptr<Enemy>> m_enemies;
  sf::VertexArray m_vertices;

public:
  Enemies();
  ~Enemies();

  virtual void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void addEnemy(Hero &hero, FloorItems &floorItems);
  void removeEnemyOnDeath();

  void makeVertices();

  const std::vector<std::unique_ptr<Enemy>> &getEnemies() const;
};