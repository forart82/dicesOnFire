#include <SFML/Graphics.hpp>
#include "Weapon/BaseWeapon.h"
#include "_COLORS.h"
#include "Form/BaseRectangle.h"

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
          2)
{
}

BaseWeapon::BaseWeapon(
    BaseRectangle weaponMenu,
    float cooldown,
    int damage,
    int numberOfSlots)
    : m_weaponMenu(weaponMenu),
      m_damage(damage),
      m_numberOfSlots(numberOfSlots)
{
}

void BaseWeapon::update(sf::Time &delta)
{
  BaseRectangle::update(delta);
  for (const auto &[key, diceSlot] : m_diceSlots)
  {
    diceSlot->update(delta);
  }
}

void BaseWeapon::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  BaseRectangle::draw(target, states);
  for (const auto &[key, diceSlot] : m_diceSlots)
  {
    target.draw(*diceSlot);
  }
}

void BaseWeapon::makeDiceSlot(int slotId)
{
  m_diceSlots[slotId] = std::make_unique<DiceSlot>();
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
