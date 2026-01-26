#include <SFML/Graphics.hpp>
#include <iostream>
#include "Weapon/BladedWeapon.h"
#include "Weapon/BaseWeapon.h"
#include "_COLORS.h"
#include "Form/BaseRectangle.h"

BladedWeapon::BladedWeapon()
    : BladedWeapon(
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

BladedWeapon::BladedWeapon(
    BaseRectangle weaponMenu,
    float cooldown,
    int damage,
    int numberOfSlots,
    int weaponSlotNumber)
    : BaseWeapon(
          weaponMenu,
          cooldown,
          damage,
          numberOfSlots,
          weaponSlotNumber)
{
  makeDiceSlots();
}

BladedWeapon::~BladedWeapon() {};

void BladedWeapon::update(sf::Time &delta)
{
  BaseWeapon::update(delta);
}

void BladedWeapon::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  BaseWeapon::draw(target, states);
}