#include "Entity/BladedWeapon.h"

BladedWeapon::BladedWeapon()
    : BladedWeapon(
          std::make_unique<Rectangle>(),
          5,
          7,
          2,
          1,
          0,
          0,
          0,
          0)
{
}

BladedWeapon::BladedWeapon(
    std::unique_ptr<Rectangle> bodyBox,
    float cooldown,
    int damage,
    int numberOfSlots,
    int weaponSlotNumber,
    int left,
    int top,
    int assetsLeft,
    int assetsTop)
    : Weapon(
          std::move(bodyBox),
          cooldown,
          damage,
          numberOfSlots,
          weaponSlotNumber,
          left,
          top,
          assetsLeft,
          assetsTop)
{
  makeDiceSlots();
}

BladedWeapon::~BladedWeapon() {};

void BladedWeapon::update(sf::Time &delta)
{
  Weapon::update(delta);
}

void BladedWeapon::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  Weapon::draw(target, states);
}