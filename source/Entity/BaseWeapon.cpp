#include "Entity/BaseWeapon.h"

BaseWeapon::BaseWeapon()
{
  Dragable::bind(m_weaponBody.get());
  Attackable::bind(m_ownerBody);
}

void BaseWeapon::update(sf::Time &delta)
{
  if (m_weaponSlotNumber)
  {
    m_weaponBody->update(delta);
    for (const auto &[key, diceSlot] : m_diceSlots)
    {
      diceSlot->update(delta);
    }
    m_attackTimer->update(delta);
  }
}

void BaseWeapon::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if (m_weaponSlotNumber)
  {
    target.draw(*m_weaponBody);
    for (const auto &[key, diceSlot] : m_diceSlots)
    {
      target.draw(*diceSlot);
    }
    target.draw(*m_attackTimer);
  }
}

void BaseWeapon::makeDiceSlot(int slotId)
{
  std::string diceSlotKey = "WEAPONSLOT_" + std::to_string(m_weaponSlotNumber) + "_WEAPON_DICESLOT_" + std::to_string(slotId);
  m_diceSlots[slotId] = m_game->getDiceSlotManager().create<DiceSlot>();

  // TO REMOVE
  // TO MODIFY
  // Its the diceSlot who has the timer
  // m_timers[slotId] = std::make_unique<Timer>(
  //     std::make_unique<RectangleX2>(m_game->getConfigLoader().get<RectangleX2>(diceSlotKey + "_TIMER")),
  //     5,
  //     true);
}

void BaseWeapon::makeDiceSlots()
{
  for (int i = 1; i <= m_numberOfSlots; i++)
  {
    makeDiceSlot(i);
  }
}

void BaseWeapon::setBody(std::unique_ptr<Rectangle> body)
{
  m_weaponBody = std::move(body);
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
  VertexRectangleDrawable::setVertexBodyPosition(position);
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
         std::to_string(m_attackDamage) +
         "\n" +
         "Cooldown: " +
         std::to_string(m_attackTimer->getCoolDown()) +
         "\n" +
         "Speed : " +
         std::to_string(m_attackSpeed);
}

const sf::FloatRect &BaseWeapon::getGlobalBounds() const
{
  return VertexRectangleDrawable::getVertexBodyGlobalBounds();
}

const sf::Vector2f &BaseWeapon::getPosition() const
{
  return VertexRectangleDrawable::getVertexBodyCenter();
}