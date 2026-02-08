#include "Entity/Weapon.h"

Weapon::Weapon()
    : Weapon(
          std::make_unique<Rectangle>(),
          5,
          7,
          2,
          1)
{
}

Weapon::Weapon(
    std::unique_ptr<Rectangle> bodyBox,
    float cooldown,
    int damage,
    int numberOfSlots,
    int weaponSlotNumber)
    : m_bodyBox(std::move(bodyBox)),
      m_damage(damage),
      m_numberOfSlots(numberOfSlots),
      m_weaponSlotNumber(weaponSlotNumber)
{
}

void Weapon::update(sf::Time &delta)
{
  m_bodyBox->update(delta);
  for (const auto &[key, diceSlot] : m_diceSlots)
  {
    diceSlot->update(delta);
  }
  for (const auto &[key, timer] : m_timers)
  {
    timer->update(delta);
  }
}

void Weapon::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(*m_bodyBox);
  for (const auto &[key, diceSlot] : m_diceSlots)
  {
    target.draw(*diceSlot);
  }
  for (const auto &[key, timer] : m_timers)
  {
    target.draw(*timer);
  }
}

void Weapon::makeDiceSlot(int slotId)
{
  std::string diceSlotKey = "WEAPONSLOT_" + std::to_string(m_weaponSlotNumber) + "_WEAPON_DICESLOT_" + std::to_string(slotId);
  m_diceSlots[slotId] = std::make_unique<DiceSlot>(std::make_unique<Circle>(configLoader::getCircle(diceSlotKey)));
  m_timers[slotId] = std::make_unique<Timer>(
      std::make_unique<RectangleX2>(configLoader::getRectangleX2(diceSlotKey + "_TIMER")),
      5,
      true);
}

void Weapon::makeDiceSlots()
{
  for (int i = 1; i <= m_numberOfSlots; i++)
  {
    makeDiceSlot(i);
  }
}

void Weapon::setDamage(int damage)
{
  m_damage = damage;
}
void Weapon::setNumberOfSlots(int numberOfSlots)
{
  m_numberOfSlots = numberOfSlots;
}

const int &Weapon::getDamage() const
{
  return m_damage;
}
const int &Weapon::getNumberOfSlots() const
{
  return m_numberOfSlots;
}
