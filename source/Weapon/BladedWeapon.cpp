#include <SFML/Graphics.hpp>
#include "Weapon/BladedWeapon.h"
#include "Weapon/_BaseWeapon.h"
#include "_COLORS.h"

BladedWeapon::BladedWeapon()
    : BladedWeapon(
          sf::Vector2f(100.f, 100.f),
          sf::Vector2f(100.f, 100.f),
          colors::COLOR_BLUE_AQUA,
          colors::COLOR_BLUE_CLOUDY_AQUA,
          true,
          5,
          7,
          2)
{
}

BladedWeapon::BladedWeapon(
    sf::Vector2f position,
    sf::Vector2f size,
    sf::Color fillColor,
    sf::Color outlineColor,
    bool isActive,
    float cooldown,
    int damage,
    int numberOfSlots)
    : _BaseWeapon(
          position,
          size,
          fillColor,
          outlineColor,
          isActive,
          cooldown,
          damage,
          numberOfSlots) {}

BladedWeapon::~BladedWeapon() {};

void BladedWeapon::update(sf::Time &delta)
{
  _BaseWeapon::update(delta);
}

void BladedWeapon::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  _BaseWeapon::draw(target, states);
}