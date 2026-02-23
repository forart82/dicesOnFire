#pragma once

class Game;

class Gameable
{
protected:
  Game *m_game = nullptr;

public:
  Gameable() = default;
  virtual ~Gameable() = default;
  virtual void setGame(Game *game) { m_game = game; }
};