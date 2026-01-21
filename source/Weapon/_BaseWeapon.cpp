#include <SFML/Graphics.hpp>
#include "Weapon/_BaseWeapon.h"
#include "_COLORS.h"

_BaseWeapon::_BaseWeapon()
    : _BaseWeapon(
          sf::Vector2f(100.f, 100.f),
          sf::Vector2f(100.f, 100.f),
          colors::COLOR_BLUE_AQUA,
          colors::COLOR_BLUE_CLOUDY_AQUA,
          true,
          5,
          7,
          2)
{
}

_BaseWeapon::_BaseWeapon(
    sf::Vector2f position,
    sf::Vector2f size,
    sf::Color fillColor,
    sf::Color outlineColor,
    bool isActive,
    float cooldown,
    int damage,
    int numberOfSlots)
    : _BaseRectangle(
          position,
          size,
          fillColor,
          outlineColor,
          isActive),
      m_damage(damage),
      m_numberOfSlots(numberOfSlots)
{
}

void _BaseWeapon::update(sf::Time &delta)
{
  _BaseRectangle::update(delta);
  for (const auto &[key, diceSlot] : m_diceSlots)
  {
    diceSlot->update(delta);
  }
}

void _BaseWeapon::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  _BaseRectangle::draw(target, states);
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
