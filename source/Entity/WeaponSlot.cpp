#include "Entity/WeaponSlot.h"

WeaponSlot::WeaponSlot()
    : WeaponSlot(
          std::make_unique<Rectangle>(),
          5,
          1)
{
}

WeaponSlot::WeaponSlot(
    std::unique_ptr<Rectangle> bodyBox,
    float cooldown,
    int weaponSlotNumber)
    : m_bodyBox(std::move(bodyBox)),
      m_weaponSlotNumber(weaponSlotNumber)

{
  std::string weaponSlotKey = "WEAPONSLOT_" + std::to_string(m_weaponSlotNumber);
  m_timer = std::make_unique<Timer>(
      std::make_unique<RectangleX2>(configLoader::get<RectangleX2>(weaponSlotKey + "_TIMER")),
      cooldown,
      true);
  fakeDropWeaponInSlot(weaponSlotKey);
}
WeaponSlot::~WeaponSlot() {}

void WeaponSlot::update(sf::Time &delta)
{
  m_bodyBox->update(delta);
  m_timer->update(delta);
  m_bladedWeapon->update(delta);
}

void WeaponSlot::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(*m_bodyBox);
  target.draw(*m_timer);
  target.draw(*m_bladedWeapon);
}

void WeaponSlot::fakeDropWeaponInSlot(std::string weaponSlotKey)
{
  m_bladedWeapon = std::make_unique<BladedWeapon>(
      std::make_unique<Rectangle>(configLoader::get<Rectangle>(weaponSlotKey + "_WEAPON")),
      randomHelper::GET_RANDOM_NUMBER_INT(3, 5),
      randomHelper::GET_RANDOM_NUMBER_INT(1, 7),
      randomHelper::GET_RANDOM_NUMBER_INT(1, 2),
      m_weaponSlotNumber,
      0,
      0,
      0,
      0);
}