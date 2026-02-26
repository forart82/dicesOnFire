#include "Ability/Attackable.h"

void Attackable::bind(
    Rectangle *attackableBody,
    Timer *attackableTimer,
    Circle *attackableRangeCircle)
{
  m_attackableBody = attackableBody;
  m_attackableTimer = attackableTimer;
  m_attackableRangeCircle = attackableRangeCircle;
}

void Attackable::updateAttackable(sf::Time &delta)
{
  assert(m_attackableBody != nullptr && "ERROR: Attackable body is not bound!");

  // 1. Tick the timer down
  if (m_attackableTimer)
  {
    m_attackableTimer->update(delta); // Adjust to your Timer's actual update function
  }

  // 2. Glue the visual radar circle to the weapon's physical body
  if (m_attackableRangeCircle)
  {
    // We get the position from the observing pointer!
    sf::Vector2f currentPos = m_attackableBody->getShape().getPosition();

    // You might need to offset this so the center of the circle
    // matches the center of the rectangle, rather than the top-left corner!
    m_attackableRangeCircle->setPosition(currentPos);
  }
}

void Attackable::setAttackDamage(int attackDamage)
{
  m_attackDamage = attackDamage;
}

void Attackable::setAttackSpeed(float attackSpeed)
{
  m_attackSpeed = attackSpeed;
}

void Attackable::setCooldown(float attackCooldown)
{
  attackCooldown = m_attackSpeed > 0 ? attackCooldown / m_attackSpeed : attackCooldown;
  m_attackableTimer->setCooldown(attackCooldown);
}
void Attackable::setAttackRangeRadius(float attackRangeRadius)
{
  m_attackRangeRadius = attackRangeRadius;
}

// --- 3. COMBAT LOGIC ---

Damageable *Attackable::checkRadar(const std::vector<Damageable *> &potentialTargets)
{
  assert(m_attackableBody != nullptr && "ERROR: Attackable body is not bound!");

  Damageable *closestTarget = nullptr;
  float shortestDistance = static_cast<float>(m_attackRangeRadius);
  sf::Vector2f myPos = m_attackableBody->getShape().getPosition();

  for (Damageable *target : potentialTargets)
  {
    if (target == nullptr || !target->isAlive())
      continue;

    sf::Vector2f targetPos = target->getDamageableBodyPosition();

    // Calculate distance
    float dx = myPos.x - targetPos.x;
    float dy = myPos.y - targetPos.y;
    float distance = std::sqrt((dx * dx) + (dy * dy));

    // If the target is inside the circle AND is the closest one we've found
    if (distance <= shortestDistance)
    {
      shortestDistance = distance;
      closestTarget = target;
    }
  }

  return closestTarget;
}

void Attackable::dealDamage(Damageable *target)
{
  // Make sure we have a valid target and a valid timer
  if (target != nullptr && target->isAlive() && m_attackableTimer)
  {
    // Check if the timer has reached 0 (adjust to your Timer's specific function)
    if (m_attackableTimer->getIsReady())
    {
      // WHACK!
      target->takeDamage(m_attackDamage);

      // Reset the stopwatch back to the weapon's speed stat
      m_attackableTimer->setIsReady(false);
    }
  }
}

// --- 4. GETTERS ---

int Attackable::getAttackDamage() const { return m_attackDamage; }
float Attackable::getAttackSpeed() const { return m_attackSpeed; }
int Attackable::getAttackRangeRadius() const { return m_attackRangeRadius; }

const Circle *Attackable::getAttackRangeCircle() const
{
  return m_attackableRangeCircle;
}