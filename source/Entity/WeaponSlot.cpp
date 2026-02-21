#include "Entity/WeaponSlot.h"

WeaponSlot::WeaponSlot(Game &game)
    : m_game(game)
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
  m_body->update(delta);
  m_timer->update(delta);
  m_bladedWeapon->update(delta);
}

void WeaponSlot::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(*m_body);
  target.draw(*m_timer);
  target.draw(*m_bladedWeapon);
}

void WeaponSlot::fakeDropWeaponInSlot(const std::string &weaponSlotKey)
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

void WeaponSlot::setBody(std::unique_ptr<Rectangle> body)
{
  m_body = std::move(body)
}
void WeaponSlot::setTimer(std::unique_ptr<Timer> timer)
{
  m_timer = std::move(timer)
}
void WeaponSlot::setBladedWeapon(std::unique_ptr<BladedWeapon> bladedWeapon)
{
  m_bladedWeapon = std::move(bladedWeapon)
}
void WeaponSlot::setWeaponSlotNumber(int weaponSlotNumber)
{
  m_weaponSlotNumber = weaponSlotNumber;
}
void WeaponSlot::setCooldown(float cooldown)
{
  m_timer->setCooldown(cooldown);
}