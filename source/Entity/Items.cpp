#include "Entity/Items.h"

void Items::addDice(std::unique_ptr<Dice> dice)
{
  m_dices.emplace_back(std::move(dice));
}

void Items::addWeapon(std::unique_ptr<Weapon> weapon)
{
  m_weapons.emplace_back(std::move(weapon));
}

const std::vector<std::unique_ptr<Dice>> &Items::getDices() const
{
  return m_dices;
}

int Items::getDicesSize() const
{
  return m_dices.size();
}

const std::vector<std::unique_ptr<Weapon>> &Items::getWeapons() const
{
  return m_weapons;
}

int Items::getWeaponSize() const
{
  return m_weapons.size();
}