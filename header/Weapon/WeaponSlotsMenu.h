#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "Weapon/WeaponSlot.h"
#include "Form/BaseRectangle.h"

class WeaponSlotsMenu : public BaseRectangle
{

private:
  BaseRectangle m_menu;
  std::map<int, std::unique_ptr<WeaponSlot>> m_weaponSlots;
  int m_weaponSlotCounter;

public:
  WeaponSlotsMenu();
  WeaponSlotsMenu(BaseRectangle menu);
  ~WeaponSlotsMenu();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void makeWeaponSlot(int weaponSlotNumber);
  void makeWeaponSlotes();
};