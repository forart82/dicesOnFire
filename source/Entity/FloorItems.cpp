#include "FloorItems.h"

FloorItems::FloorItems()
    : VertexRectangle(
          0,
          0,
          0,
          0) {}
FloorItems::~FloorItems()
{
}

void FloorItems::update(sf::Time &delta) {}

void FloorItems::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  states.texture = &textureManager::getTexture("Utumno");
  target.draw(m_vertices, states);
}

void FloorItems::addFloorItem()
{
}
