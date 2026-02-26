#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Ability/Damageable.h"
#include "Entity/Timer.h"
#include "Entity/Circle.h"
#include "Entity/Rectangle.h"

class Attackable
{

private:
  Rectangle *m_attackableBody = nullptr;
  Timer *m_attackableTimer = nullptr;
  Circle *m_attackableRangeCircle = nullptr;

protected:
  int m_attackDamage;
  float m_attackSpeed;
  int m_attackRangeRadius;

public:
  Attackable() = default;
  virtual ~Attackable() = default;

  void bind(
      Rectangle *attackableBody,
      Timer *attackableTimer,
      Circle *attackableRangeCircle);

  void Attackable::updateAttackable(sf::Time &delta);
  Damageable *Attackable::checkRadar(const std::vector<Damageable *> &targets);

  void Attackable::dealDamage(Damageable *target);

  void setAttackTimer(std::unique_ptr<Timer> attackTimer);
  void setAttackRangeCircle(std::unique_ptr<Circle> attackRangeCircle);
  void setAttackDamage(int attackDamage);
  void setAttackSpeed(float attackSpeed);
  void setCooldown(float attackCooldown);
  void setAttackRangeRadius(float attackRangeRadius);

  int getAttackDamage() const;
  float getAttackSpeed() const;
  int getAttackRangeRadius() const;
  const Circle *Attackable::getAttackRangeCircle() const;
};