#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "Entity/DiceSlot.h"
#include "Entity/Rectangle.h"
#include "Entity/Timer.h"
#include "Entity/VertexRectangle.h"
#include "Loader/ConfigLoader.h"

class Weapon : public sf::Drawable, public VertexRectangle
{
protected:
  std::unique_ptr<Rectangle> m_bodyBox;
  int m_damage;
  int m_numberOfSlots;
  int m_weaponSlotNumber;
  std::map<int, std::unique_ptr<DiceSlot>> m_diceSlots;
  std::map<int, std::unique_ptr<Timer>> m_timers;

public:
  Weapon();
  Weapon(
      std::unique_ptr<Rectangle> bodyBox,
      float cooldown,
      int damage,
      int numberOfSlots,
      int weaponSlotNumber,
      int left,
      int top,
      int assetsLft,
      int assetsTop);
  virtual ~Weapon() {};

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  void makeDiceSlot(int slotId);
  void makeDiceSlots();

  void setDamage(int damage);
  void setNumberOfSlots(int numberOfSlots);
  void setWeaponSlotNumber(int weaponSlotNumber);

  const int &getDamage() const;
  const int &getNumberOfSlots() const;
};