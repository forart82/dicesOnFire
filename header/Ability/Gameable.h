#pragma once

#include "Entity/Game.h"

class Gameable
{
protected:
  Game *m_game = nullptr;

public:
  Gameable() = default;
  virtual ~Gameable() = default;

  void setGame(Game *game) { m_game = game; }
};