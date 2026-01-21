#include <SFML/Graphics.hpp>
#include "Weapon/_BaseWeapon.h"

_BaseWeapon::_BaseWeapon()
    : _BaseWeapon(7, 2) {}

_BaseWeapon::_BaseWeapon(int damage, int numberOfSlots)
    : m_damage(damage), m_numberOfSlots(numberOfSlots)
{
}

void _BaseWeapon::update(sf::Time &delta)
{
  for (const auto &[key, diceSlot] : m_diceSlots)
  {
    diceSlot->update(delta);
  }
}

void _BaseWeapon::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  for (const auto &[key, diceSlot] : m_diceSlots)
  {
    target.draw(*diceSlot);
  }
}

void _BaseWeapon::makeDiceSlot(int slotId)
{
  m_diceSlots[slotId] = std::make_unique<DiceSlot>();
}

void _BaseWeapon::makeDiceSlots()
{
  for (int i = 1; i <= m_numberOfSlots; i++)
  {
    makeDiceSlot(i);
  }
}

void _BaseWeapon::setDamage(int damage)
{
  m_damage = damage;
}
void _BaseWeapon::setNumberOfSlots(int numberOfSlots)
{
  m_numberOfSlots = numberOfSlots;
}

const int &_BaseWeapon::getDamage() const
{
  return m_damage;
}
const int &_BaseWeapon::getNumberOfSlots() const
{
  return m_numberOfSlots;
}
