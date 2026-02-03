#pragma once

#include <SFML/Graphics.hpp>
#include "Vertex/VertexRectangle.h"

class Cell : public VertexRectangle
{

private:
public:
  Cell(int left, int top);
  ~Cell();
};
