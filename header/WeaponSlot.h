#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "DiceSlot.h"
#include "_BaseRectangle.h"
#include "_BaseWeapon.h"

class WeaponSlot : public _BaseRectangle
{

private:
  std::map<int, std::unique_ptr<DiceSlot>> m_diceSlots;
  std::unique_ptr<_BaseWeapon> m_weapon;

public:
  WeaponSlot();
  WeaponSlot(sf::Vector2f position, sf::Vector2f size, sf::Color fillColor, sf::Color outlineColor, bool isActive);
  ~WeaponSlot();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void fakeDropWeapon();
};