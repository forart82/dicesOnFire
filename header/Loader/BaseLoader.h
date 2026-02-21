#pragma once

#include "Entity/Game.h"

class BaseLoader
{

protected:
  Game &m_game;

public:
  BaseLoader(Game &game);
  virtual ~BaseLoader() = default;
};