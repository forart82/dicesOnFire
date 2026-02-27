#include "Entity/BaseItems.h"

void BaseItems::addDice(std::unique_ptr<Dice> dice)
{
  m_dices.emplace_back(std::move(dice));
}

void BaseItems::addWeapon(std::unique_ptr<BaseWeapon> weapon)
{
  m_weapons.emplace_back(std::move(weapon));
}

const std::vector<std::unique_ptr<Dice>> &BaseItems::getDices() const
{
  return m_dices;
}

int BaseItems::getDicesSize() const
{
  return m_dices.size();
}

const std::vector<std::unique_ptr<BaseWeapon>> &BaseItems::getWeapons() const
{
  return m_weapons;
}

int BaseItems::getWeaponSize() const
{
  return m_weapons.size();
}