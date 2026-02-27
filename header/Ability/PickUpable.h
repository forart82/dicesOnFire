#pragma once

class Collectorable;
class Rectangle;
class PickUpable
{
private:
  Rectangle *m_pickUpableBody = nullptr;

public:
  PickUpable() = default;
  virtual ~PickUpable() = default;

  void bind(Rectangle *pickUpableBody);

  bool canBePickedUp(Collectorable *collector) const;
};