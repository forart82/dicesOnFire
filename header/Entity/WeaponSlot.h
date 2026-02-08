#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "Entity/Timer.h"
#include "Entity/DiceSlot.h"
#include "Entity/WeaponSlot.h"
#include "Entity/BladedWeapon.h"
#include "Entity/Rectangle.h"
#include "Helper/RandomHelper.h"

class WeaponSlot : public sf::Drawable
{

private:
  std::unique_ptr<Rectangle> m_bodyBox;
  std::unique_ptr<Timer> m_timer;
  std::unique_ptr<BladedWeapon> m_bladedWeapon;
  int m_weaponSlotNumber;

public:
  WeaponSlot();
  WeaponSlot(
      std::unique_ptr<Rectangle> bodyBox,
      float cooldown,
      int weaponSlotNumber);
  ~WeaponSlot();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void fakeDropWeaponInSlot(std::string weaponSlotKey);
};