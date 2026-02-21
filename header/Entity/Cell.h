#pragma once

#include <SFML/Graphics.hpp>
#include "Ability/VertexRectangleDrawable.h"
#include "Helper/RandomHelper.h"

class Cell : public VertexRectangleDrawable
{

private:
public:
  Cell(Game &game);
  ~Cell();
};
