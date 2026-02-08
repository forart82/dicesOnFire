#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/VertexRectangle.h"
#include "Helper/RandomHelper.h"

class Cell : public VertexRectangle
{

private:
public:
  Cell(int left, int top);
  ~Cell();
};
