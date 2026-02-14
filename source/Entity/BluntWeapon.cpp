#include "Entity/BluntWeapon.h"

BluntWeapon::BluntWeapon(
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
}

BluntWeapon::~BluntWeapon() {};