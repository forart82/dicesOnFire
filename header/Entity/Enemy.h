#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/BaseEntity.h"
#include "Entity/Hero.h"
#include "_HELPERS.h"

class Enemy : public BaseEntity
{
private:
  Hero &m_hero;
  bool m_houndHero;

  int m_assetsLeft;
  int m_assetsTop;

  sf::Vector2f m_leftTop;
  sf::Vector2f m_rightTop;
  sf::Vector2f m_leftBottom;
  sf::Vector2f m_rightBottom;

  sf::Vector2f m_assetsLeftTop;
  sf::Vector2f m_assetsRightTop;
  sf::Vector2f m_assetsLeftBottom;
  sf::Vector2f m_assetsRightBottom;

public:
  Enemy(Hero &hero);
  Enemy(Hero &hero,
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

  void houndHero();

  bool &getHoundHero();

  sf::Vector2f &getLeftTop();
  sf::Vector2f &getRightTop();
  sf::Vector2f &getLeftBottom();
  sf::Vector2f &getRightBottom();

  sf::Vector2f &getAssetsLeftTop();
  sf::Vector2f &getAssetsRightTop();
  sf::Vector2f &getAssetsLeftBottom();
  sf::Vector2f &getAssetsRightBottom();
};