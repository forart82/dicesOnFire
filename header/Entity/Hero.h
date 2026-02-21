#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity/Game.h"
#include "Entity/BaseCharacterBody.h"
#include "Entity/Rectangle.h"
#include "Entity/RectangleX2.h"
#include "Globals/Enums.h"
#include "Loader/TextureLoader.h"

class Hero : public BaseCharacterBody
{
private:
  Game &m_game;

  sf::Vector2f m_direction;

public:
  Hero(Game &game);
  ~Hero();

  void update(sf::Time &delta) override;

  void move(const sf::Time &delta);
};