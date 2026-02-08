#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "Entity/WeaponSlot.h"
#include "Entity/Rectangle.h"

class WeaponSlotsMenu : public sf::Drawable
{

private:
  std::unique_ptr<Rectangle> m_bodyBox;
  std::map<int, std::unique_ptr<WeaponSlot>> m_weaponSlots;
  int m_weaponSlotCounter;

public:
  WeaponSlotsMenu();
  WeaponSlotsMenu(std::unique_ptr<Rectangle> bodyBox);
  ~WeaponSlotsMenu();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void makeWeaponSlot(int weaponSlotNumber);
  void makeWeaponSlotes();
};