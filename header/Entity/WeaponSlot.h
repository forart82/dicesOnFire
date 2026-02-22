#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "Entity/Game.h"
#include "Entity/Timer.h"
#include "Entity/DiceSlot.h"
#include "Entity/WeaponSlot.h"
#include "Entity/BladedWeapon.h"
#include "Entity/Rectangle.h"
#include "Helper/RandomHelper.h"

class WeaponSlot : public sf::Drawable
{

private:
    std::unique_ptr<Rectangle> m_body;
  std::unique_ptr<Timer> m_timer;
  std::unique_ptr<BladedWeapon> m_bladedWeapon;

  int m_weaponSlotNumber;

public:
  WeaponSlot();
  ~WeaponSlot();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void fakeDropWeaponInSlot(const std::string &weaponSlotKey);

  void setBody(std::unique_ptr<Rectangle> body);
  void setTimer(std::unique_ptr<Timer> timer);
  void setBladedWeapon(std::unique_ptr<BladedWeapon> bladedWeapon);
  void setWeaponSlotNumber(int weaponSlotNumber);
  void setCooldown(float cooldown);
};