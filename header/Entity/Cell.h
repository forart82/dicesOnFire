#pragma once

#include <SFML/Graphics.hpp>
#include "Ability/VertexRectangleDrawable.h"
#include "Entity/BaseEntity.h"
#include "Helper/RandomHelper.h"

class Cell : public BaseEntity, public VertexRectangleDrawable
{

private:
public:
  Cell();
  ~Cell();
};
