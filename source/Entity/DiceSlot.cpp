#include "Entity/DiceSlot.h"

DiceSlot::DiceSlot()
    : m_BodyCircle(std::make_unique<Circle>())
{
}

DiceSlot::DiceSlot(std::unique_ptr<Circle> bodyCircle)
    : m_BodyCircle(std::move(bodyCircle))
{
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
    target.draw(*m_BodyCircle);
};