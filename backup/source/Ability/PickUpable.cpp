#include "Ability/PickUpable.h"

void PickUpable::bind(
    Rectangle *pickUpableBody)
{
  m_pickUpableBody = pickUpableBody;
}

bool PickUpable::canBePickedUp(Collectorable *collector) const
{
  if (m_pickUpableBody == nullptr)
    return false;

  // Ask the hero: "Is my position inside your pickup circle?"
  return collector->insideColletorableRange(m_pickUpableBody->getShape().getGeometricCenter());
}