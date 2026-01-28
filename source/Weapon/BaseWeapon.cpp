#include <SFML/Graphics.hpp>
#include "Weapon/BaseWeapon.h"
#include "_COLORS.h"
#include "Form/BaseRectangle.h"
#include "ConfigManager.h"

BaseWeapon::BaseWeapon()
    : BaseWeapon(
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

BaseWeapon::BaseWeapon(
    BaseRectangle weaponMenu,
    float cooldown,
    int damage,
    int numberOfSlots,
    int weaponSlotNumber)
    : BaseRectangle(weaponMenu),
      m_damage(damage),
      m_numberOfSlots(numberOfSlots),
      m_weaponSlotNumber(weaponSlotNumber)
{
}

void BaseWeapon::update(sf::Time &delta)
{
  BaseRectangle::update(delta);
  for (const auto &[key, diceSlot] : m_diceSlots)
  {
    diceSlot->update(delta);
  }
  for (const auto &[key, timer] : m_timers)
  {
    timer->update(delta);
  }
}

void BaseWeapon::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  BaseRectangle::draw(target, states);
  for (const auto &[key, diceSlot] : m_diceSlots)
  {
    target.draw(*diceSlot);
  }
  for (const auto &[key, timer] : m_timers)
  {
    target.draw(*timer);
  }
}

void BaseWeapon::makeDiceSlot(int slotId)
{
  std::string diceSlotKey = "WEAPONSLOT_" + std::to_string(m_weaponSlotNumber) + "_WEAPON_DICESLOT_" + std::to_string(slotId);
  m_diceSlots[slotId] = std::make_unique<DiceSlot>(config::getCircle(diceSlotKey));
  m_timers[slotId] = std::make_unique<Timer>(
      config::getRectangleX2(diceSlotKey + "_TIMER"),
      5,
      true);
}

void BaseWeapon::makeDiceSlots()
{
  for (int i = 1; i <= m_numberOfSlots; i++)
  {
    makeDiceSlot(i);
  }
}

void BaseWeapon::setDamage(int damage)
{
  m_damage = damage;
}
void BaseWeapon::setNumberOfSlots(int numberOfSlots)
{
  m_numberOfSlots = numberOfSlots;
}

const int &BaseWeapon::getDamage() const
{
  return m_damage;
}
const int &BaseWeapon::getNumberOfSlots() const
{
  return m_numberOfSlots;
}
