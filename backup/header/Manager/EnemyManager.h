#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Entity/Enemy.h"
#include "Entity/FloorItems.h"
#include "Helper/RandomHelper.h"
#include "Loader/ConfigLoader.h"
#include "Manager/BaseManager.h"

class EnemyManager : public BaseManager
{
private:
  std::unique_ptr<Rectangle> m_enemyBody;
  std::unique_ptr<RectangleX2> m_enemyHealthBar;
  std::unique_ptr<Circle> m_enemyWatchRange;
  std::unique_ptr<Circle> m_enemyShortRange;
  std::unique_ptr<Circle> m_enemyLongRange;
  std::unique_ptr<Circle> m_enemyPickUpUpRange;

public:
  EnemyManager();
  ~EnemyManager();

  template <typename T>
  void addPosition(const std::unique_ptr<T> &component, const sf::Vector2f &offset);

  std::unique_ptr<Enemy> createEnemy();
};