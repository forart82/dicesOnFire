#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "Timer.h"
#include "Dice/Dice.h"
#include "Weapon/WeaponSlot.h"
#include "Weapon/BladedWeapon.h"
#include "Form/_BaseRectangle.h"

class WeaponSlot : public _BaseRectangle
{

private:
  std::map<int, Dice *> m_dices;
  std::unique_ptr<Timer> m_timer;
  std::unique_ptr<BladedWeapon> m_weapon;

public:
  WeaponSlot();
  WeaponSlot(sf::Vector2f position, sf::Vector2f size, sf::Color fillColor, sf::Color outlineColor, bool isActive, float cooldown);
  ~WeaponSlot();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void placeDiceInSlot(int slotNumber, Dice *dice);
  void setTimerCooldown(float cooldown);
  void fakeDropWeapon();
};