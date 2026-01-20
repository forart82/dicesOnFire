#include <SFML/Graphics.hpp>
#include "../header/WeaponSlot.h"
#include "../header/_BaseRectangle.h"
#include "../header/_GLOBALS.h"
#include "../header/WeaponHelper.h"

WeaponSlot::WeaponSlot()
    : WeaponSlot(
          sf::Vector2f(100.f, 100.f),
          sf::Vector2f(100.f, 100.f),
          COLOR_BLUE_AQUA,
          COLOR_GRAYSCALE_DENSE_WHITE,
          true) {}

WeaponSlot::WeaponSlot(sf::Vector2f position, sf::Vector2f size, sf::Color fillColor, sf::Color outlineColor, bool isActive)
    : _BaseRectangle(position, size, fillColor, outlineColor, isActive)
{
}

WeaponSlot::~WeaponSlot() {}

void WeaponSlot::update(sf::Time &delta)
{
}

void WeaponSlot::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  _BaseRectangle::draw(target, states);
}

void WeaponSlot::fakeDropWeapon()
{
  m_weapon = CREATE_WEAPON();
}