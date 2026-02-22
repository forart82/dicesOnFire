#include "Entity/DiceSlot.h"

DiceSlot::DiceSlot()
    : m_game(game)
{
  m_body = std::make_unique<Circle>();
}

DiceSlot::~DiceSlot()
{
}

void DiceSlot::update(sf::Time &delta)
{
  m_BodyCircle->update(delta);
}

void DiceSlot::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(*m_body);
};

void DiceSlot::setBody(std::unique_ptr<Circle> body)
{
  m_body = std::move(body);
}