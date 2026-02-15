#include "Entity/FloorItems.h"

FloorItems::FloorItems()
    : VertexRectangle(
          0,
          0,
          0,
          0)
{
  m_texture = &textureLoader::getTexture("Utumno");
}
FloorItems::~FloorItems()
{
}

void FloorItems::update(sf::Time &delta) {}

void FloorItems::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  states.texture = m_texture;
  target.draw(m_vertices, states);
}