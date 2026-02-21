#include "Entity/BaseWeapon.h"

BaseWeapon::BaseWeapon(Game &game)
    : VertexRectangleDrawable(game),
      Dragable(game),
      m_game(game)
{
}

void BaseWeapon::update(sf::Time &delta)
{
  if (m_weaponSlotNumber)
  {
    m_body->update(delta);
    for (const auto &[key, diceSlot] : m_diceSlots)
    {
      diceSlot->update(delta);
    }
    for (const auto &[key, timer] : m_timers)
    {
      timer->update(delta);
    }
  }
}

void BaseWeapon::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if (m_weaponSlotNumber)
  {
    target.draw(*m_body);
    for (const auto &[key, diceSlot] : m_diceSlots)
    {
      target.draw(*diceSlot);
    }
    for (const auto &[key, timer] : m_timers)
    {
      target.draw(*timer);
    }
  }
}

void BaseWeapon::makeDiceSlot(int slotId)
{
  std::string diceSlotKey = "WEAPONSLOT_" + std::to_string(m_weaponSlotNumber) + "_WEAPON_DICESLOT_" + std::to_string(slotId);
  m_diceSlots[slotId] = std::make_unique<DiceSlot>(std::make_unique<Circle>(configLoader::get<Circle>(diceSlotKey)));
  m_timers[slotId] = std::make_unique<Timer>(
      std::make_unique<RectangleX2>(configLoader::get<RectangleX2>(diceSlotKey + "_TIMER")),
      5,
      true);
}

void BaseWeapon::makeDiceSlots()
{
  for (int i = 1; i <= m_numberOfSlots; i++)
  {
    makeDiceSlot(i);
  }
}

void BaseWeapon::setDamage(int damage)
{
  m_damage = damage;
}
void BaseWeapon::setNumberOfSlots(int numberOfSlots)
{
  m_numberOfSlots = numberOfSlots;
}

void BaseWeapon::setWeaponSlotNumber(int weaponSlotNumber)
{
  for (int i = 1; i <= m_diceSlots.size() + 1; i++)
  {
    std::string diceSlotKey = "WEAPONSLOT_" + std::to_string(weaponSlotNumber) + "_WEAPON_DICESLOT_" + std::to_string(i);
  }
}

void BaseWeapon::setPosition(const sf::Vector2f &position)
{
  VertexRectangleDrawable::setBodyPosition(position);
}

int BaseWeapon::getDamage() const
{
  return m_damage;
}
int BaseWeapon::getNumberOfSlots() const
{
  return m_numberOfSlots;
}

const std::string &BaseWeapon::getName() const
{
  return m_name;
}
const std::string &BaseWeapon::getStats() const
{
  return "Damage: " +
         std::to_string(m_damage);
}

const sf::FloatRect &BaseWeapon::getGlobalBounds() const
{
  return VertexRectangleDrawable::getGlobalBounds();
}

const sf::Vector2f &BaseWeapon::getPosition() const
{
  return VertexRectangleDrawable::getBodyCenter();
}