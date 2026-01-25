#include <SFML/Graphics.hpp>
#include "Weapon/Sword.h"
#include "Weapon/BladedWeapon.h"
#include "_COLORS.h"
#include "Form/BaseRectangle.h"

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
          2) {}

Sword::Sword(
    BaseRectangle swordMenu,
    float cooldown,
    int damage,
    int numberOfSlots)
    : BladedWeapon(
          swordMenu,
          cooldown,
          damage,
          numberOfSlots) {}

Sword::~Sword() {};

void Sword::update(sf::Time &delta)
{
  BladedWeapon::update(delta);
}

void Sword::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  BladedWeapon::draw(target, states);
}