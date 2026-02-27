#include "Entity/BaseItems.h"
#include "Entity/Dice.h"
#include "Entity/BaseWeapon.h"

BaseItems::~BaseItems() = default;

void BaseItems::addDice(std::unique_ptr<Dice> dice)
{
  m_dices.emplace_back(std::move(dice));
}

void BaseItems::addWeapon(std::unique_ptr<BaseWeapon> weapon)
{
  m_weapons.emplace_back(std::move(weapon));
}

std::vector<std::unique_ptr<Dice>> &BaseItems::getDices()
{
  return m_dices;
}

int BaseItems::getDicesSize() const
{
  return m_dices.size();
}

std::vector<std::unique_ptr<BaseWeapon>> &BaseItems::getWeapons()
{
  return m_weapons;
}

int BaseItems::getWeaponSize() const
{
  return m_weapons.size();
}