#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "Dice/DiceSlot.h"

class _BaseWeapon : public sf::Drawable
{
protected:
  int m_damage;
  int m_numberOfSlots;
  std::map<int, std::unique_ptr<DiceSlot>> m_diceSlots;

public:
  _BaseWeapon();
  _BaseWeapon(int damage, int numberOfSlots);
  virtual ~_BaseWeapon() {};

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  void makeDiceSlot(int slotId);
  void makeDiceSlots();

  void setDamage(int damage);
  void setNumberOfSlots(int numberOfSlots);

  const int &getDamage() const;
  const int &getNumberOfSlots() const;
};