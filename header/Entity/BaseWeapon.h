#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "Ability/Dragable.h"
#include "Ability/VertexRectangleDrawable.h"
#include "Entity/DiceSlot.h"
#include "Entity/Rectangle.h"
#include "Entity/Timer.h"
#include "Loader/ConfigLoader.h"
#include "Loader/RandomNameLoader.h"

class BaseWeapon : public sf::Drawable, public VertexRectangleDrawable, public Dragable
{
protected:
  Game &m_game;

  std::unique_ptr<Rectangle> m_body;
  std::string m_name;
  int m_damage;
  int m_numberOfSlots;
  int m_weaponSlotNumber;
  std::map<int, std::unique_ptr<DiceSlot>> m_diceSlots;
  std::map<int, std::unique_ptr<Timer>> m_timers;

public:
  BaseWeapon(Game &game);
  virtual ~BaseWeapon() = default;

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  void makeDiceSlot(int slotId);
  void makeDiceSlots();

  void setDamage(int damage);
  void setNumberOfSlots(int numberOfSlots);
  void setWeaponSlotNumber(int weaponSlotNumber);
  void setPosition(const sf::Vector2f &position);

  int getDamage() const;
  int getNumberOfSlots() const;

  const std::string &getName() const;
  const std::string &getStats() const;

  const sf::FloatRect &getGlobalBounds() const;
  const sf::Vector2f &getPosition() const;
};