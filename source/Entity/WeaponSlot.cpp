#include "Entity/WeaponSlot.h"

WeaponSlot::WeaponSlot()
{
  std::string weaponSlotKey = "WEAPONSLOT_" + std::to_string(m_weaponSlotNumber);
  m_timer = std::make_unique<Timer>();
  m_timer->setGame(m_game);

  m_timer->setBody(std::make_unique<RectangleX2>(m_game->getConfigLoader().get<RectangleX2>(weaponSlotKey + "_TIMER")));
  m_timer->setCooldown(3);
  m_timer->setIsVertical(true);
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
}

void WeaponSlot::setBody(std::unique_ptr<Rectangle> body)
{
  m_body = std::move(body);
}
void WeaponSlot::setTimer(std::unique_ptr<Timer> timer)
{
  m_timer = std::move(timer);
}
void WeaponSlot::setBladedWeapon(std::unique_ptr<BladedWeapon> bladedWeapon)
{
  m_bladedWeapon = std::move(bladedWeapon);
}
void WeaponSlot::setWeaponSlotNumber(int weaponSlotNumber)
{
  m_weaponSlotNumber = weaponSlotNumber;
}
void WeaponSlot::setCooldown(float cooldown)
{
  m_timer->setCooldown(cooldown);
}