#pragma once

#include "Entity/BaseEntity.h"
#include "Entity/Cell.h"
#include "Helper/GridHelper.h"
#include "Loader/TextureLoader.h"

class Grid : public BaseEntity
{

private:
  std::map<std::pair<int, int>, Cell> m_cells;

public:
  Grid();
  ~Grid();

  const Cell &findOrMakeCell(int x, int y);
};