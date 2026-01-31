#include "Weapon/Sword.h"

Sword::Sword()
    : Sword(
          BaseRectangle(
              sf::Vector2f(100.f, 100.f),
              sf::Vector2f(100.f, 100.f),
              1,
              true,
              colors::COLOR_BLUE_AQUA,
              colors::COLOR_BLUE_CLOUDY_AQUA),
          5,
          7,
          2,
          1)
{
}

Sword::Sword(
    BaseRectangle swordMenu,
    float cooldown,
    int damage,
    int numberOfSlots,
    int weaponSlotNumber)
    : BladedWeapon(
          swordMenu,
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