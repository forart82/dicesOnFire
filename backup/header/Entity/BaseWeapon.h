#pragma once

#include <memory>
#include <string>
#include <map>
#include "Ability/Attackable.h"
#include "Ability/Dragable.h"
#include "Ability/Hoverable.h"
#include "Ability/PickUpable.h"
#include "Ability/VertexRectangleDrawable.h"
#include "Entity/Game.h"
#include "Entity/BaseEntity.h"
#include "Entity/Rectangle.h"
#include "Loader/ConfigLoader.h"
#include "Loader/RandomNameLoader.h"

class Timer;
class DiceSlot;
class ToolTip;
class BaseWeapon
    : public BaseEntity,
      public sf::Drawable,
      public Attackable,
      public Dragable,
      public Hoverable,
      public PickUpable,
      public VertexRectangleDrawable
{

private:
  Rectangle *m_ownerBody = nullptr;

protected:
  std::unique_ptr<Rectangle> m_weaponBody;
  std::unique_ptr<Timer> m_weaponTimer;
  std::unique_ptr<Circle> m_weaponRangeCircle;
  std::map<int, std::unique_ptr<DiceSlot>> m_diceSlots;

  std::unique_ptr<ToolTip> m_weaponToolTip;

  std::string m_name;

  int m_numberOfSlots;
  int m_weaponSlotNumber;

public:
  BaseWeapon();
  virtual ~BaseWeapon() = default;

  void bind(Rectangle *ownerBody);

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  void makeDiceSlot(int slotId);
  void makeDiceSlots();

  void setBody(std::unique_ptr<Rectangle> body);
  void setWeaponTimer(std::unique_ptr<Timer> weaponTimer);
  void setWeaponRangeCircle(std::unique_ptr<Circle> weaponRangeCircle);
  void setNumberOfSlots(int numberOfSlots);
  void setWeaponSlotNumber(int weaponSlotNumber);
  void setPosition(const sf::Vector2f &position);

  int getNumberOfSlots() const;

  const sf::Vector2f &getPosition() const;

  const sf::FloatRect &getGlobalBounds() const override;

  void setHoverableShowUpTime(float hoverableShowUpTime) override;
  std::string getName() const override;
  std::string getStats() const override;
};