#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "Weapon/WeaponSlot.h"
#include "Form/_BaseRectangle.h"

class WeaponSlotsMenu : public _BaseRectangle
{

private:
  std::map<int, std::unique_ptr<WeaponSlot>> m_weaponSlots;
  int m_weaponSlotCounter;

public:
  WeaponSlotsMenu();
  WeaponSlotsMenu(
      sf::Vector2f position,
      sf::Vector2f size,
      sf::Color fillColor,
      sf::Color outlineColor,
      bool isActive);
  ~WeaponSlotsMenu();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void makeWeaponSlot(int weaponSlotNumber);
  void makeWeaponSlotes();
};