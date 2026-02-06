#include "Weapon/WeaponSlot.h"

WeaponSlot::WeaponSlot()
    : WeaponSlot(
          BaseRectangle(),
          5,
          1)
{
}

WeaponSlot::WeaponSlot(
    BaseRectangle weaponSlotMenu,
    float cooldown,
    int weaponSlotNumber)
    : BaseRectangle(weaponSlotMenu),
      m_weaponSlotNumber(weaponSlotNumber)

{
  std::string weaponSlotKey = "WEAPONSLOT_" + std::to_string(m_weaponSlotNumber);
  m_timer = std::make_unique<Timer>(
      configManager::getRectangleX2(weaponSlotKey + "_TIMER"),
      cooldown,
      true);
  fakeDropWeaponInSlot(weaponSlotKey);
}
WeaponSlot::~WeaponSlot() {}

void WeaponSlot::update(sf::Time &delta)
{
  BaseRectangle::update(delta);
  m_timer->update(delta);
  m_bladedWeapon->update(delta);
}

void WeaponSlot::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  BaseRectangle::draw(target, states);
  target.draw(*m_timer);
  target.draw(*m_bladedWeapon);
}

void WeaponSlot::fakeDropWeaponInSlot(std::string weaponSlotKey)
{
  m_bladedWeapon = std::make_unique<BladedWeapon>(
      configManager::getRectangle(weaponSlotKey + "_WEAPON"),
      helper::GET_RANDOM_NUMBER_INT(3, 5),
      helper::GET_RANDOM_NUMBER_INT(1, 7),
      helper::GET_RANDOM_NUMBER_INT(1, 2),
      m_weaponSlotNumber);
}