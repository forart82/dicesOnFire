#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "Dice/DiceSlot.h"
#include "Form/_BaseRectangle.h"
#include "Timer.h"

class _BaseWeapon : public _BaseRectangle
{
protected:
  int m_damage;
  int m_numberOfSlots;
  std::map<int, std::unique_ptr<DiceSlot>> m_diceSlots;
  std::unique_ptr<Timer> m_timer;

public:
  _BaseWeapon();
  _BaseWeapon(
      sf::Vector2f position,
      sf::Vector2f size,
      sf::Color fillColor,
      sf::Color outlineColor,
      bool isActive,
      float cooldown,
      int damage,
      int numberOfSlots);
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