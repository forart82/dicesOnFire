#include "Entity/FloorItems.h"

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
  states.texture = &textureLoader::getTexture("Utumno");
  target.draw(m_vertices, states);
}

void FloorItems::addDice(std::unique_ptr<Dice> dice)
{
  m_dices.emplace_back(std::move(dice));
}

std::vector<std::unique_ptr<Dice>> &FloorItems::getDices()
{
  return m_dices;
}

int FloorItems::getDicesSize()
{
  return m_dices.size();
}
