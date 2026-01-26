#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "Timer.h"
#include "Dice/DiceSlot.h"
#include "Weapon/WeaponSlot.h"
#include "Weapon/BladedWeapon.h"
#include "Form/BaseRectangle.h"

class WeaponSlot : public BaseRectangle
{

private:
  std::unique_ptr<Timer> m_timer;
  std::unique_ptr<BladedWeapon> m_bladedWeapon;
  int m_weaponSlotNumber;

public:
  WeaponSlot();
  WeaponSlot(
      BaseRectangle m_weaponSlotMenu,
      float cooldown,
      int weaponSlotNumber);
  ~WeaponSlot();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void fakeDropWeaponInSlot(std::string weaponSlotKey);
};