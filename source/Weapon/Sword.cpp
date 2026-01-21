#include <SFML/Graphics.hpp>
#include "Weapon/Sword.h"
#include "Weapon/BladedWeapon.h"
#include "_COLORS.h"

Sword::Sword()
    : Sword(
          sf::Vector2f(100.f, 100.f),
          sf::Vector2f(100.f, 100.f),
          colors::COLOR_BLUE_AQUA,
          colors::COLOR_BLUE_CLOUDY_AQUA,
          true,
          5,
          7,
          2) {}

Sword::Sword(
    sf::Vector2f position,
    sf::Vector2f size,
    sf::Color fillColor,
    sf::Color outlineColor,
    bool isActive,
    float cooldown,
    int damage,
    int numberOfSlots)
    : BladedWeapon(
          position,
          size,
          fillColor,
          outlineColor,
          isActive,
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