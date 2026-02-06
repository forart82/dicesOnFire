#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "Dice/DiceSlot.h"
#include "Form/BaseRectangle.h"
#include "Timer.h"
#include "Manager/ConfigManager.h"

class BaseWeapon : public BaseRectangle
{
protected:
  int m_damage;
  int m_numberOfSlots;
  int m_weaponSlotNumber;
  std::map<int, std::unique_ptr<DiceSlot>> m_diceSlots;
  std::map<int, std::unique_ptr<Timer>> m_timers;

public:
  BaseWeapon();
  BaseWeapon(
      BaseRectangle weaponMenu,
      float cooldown,
      int damage,
      int numberOfSlots,
      int weaponSlotNumber);
  virtual ~BaseWeapon() {};

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  void makeDiceSlot(int slotId);
  void makeDiceSlots();

  void setDamage(int damage);
  void setNumberOfSlots(int numberOfSlots);

  const int &getDamage() const;
  const int &getNumberOfSlots() const;
};