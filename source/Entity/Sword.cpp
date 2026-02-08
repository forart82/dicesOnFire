#include "Entity/Sword.h"

Sword::Sword()
    : Sword(
          std::make_unique<Rectangle>(),
          5,
          7,
          2,
          1)
{
}

Sword::Sword(
    std::unique_ptr<Rectangle> bodyBox,
    float cooldown,
    int damage,
    int numberOfSlots,
    int weaponSlotNumber)
    : BladedWeapon(
          std::move(bodyBox),
          cooldown,
          damage,
          numberOfSlots,
          weaponSlotNumber) {}

Sword::~Sword() {};

void Sword::update(sf::Time &delta)
{
  BladedWeapon::update(delta);
}

void Sword::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  BladedWeapon::draw(target, states);
}