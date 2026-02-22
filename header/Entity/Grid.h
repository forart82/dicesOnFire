#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity/Game.h"
#include "Entity/Cell.h"
#include "Entity/Hero.h"
#include "Helper/GridHelper.h"
#include "Loader/TextureLoader.h"

class Grid
{

private:
    std::map<std::pair<int, int>, Cell> m_cells;

public:
  Grid();
  ~Grid();

  const Cell &findOrMakeCell(int x, int y) const;
};