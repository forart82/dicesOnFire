#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "Timer.h"
#include "Dice.h"
#include "_BaseRectangle.h"

class DiceBox : public _BaseRectangle
{

private:
  std::map<int, Dice *> m_dices;
  std::unique_ptr<Timer> m_timer;

public:
  DiceBox();
  DiceBox(sf::Vector2f position, sf::Vector2f size, sf::Color fillColor, sf::Color outlineColor, bool isActive, float cooldown);
  ~DiceBox();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void placeDiceInSlot(int slotNumber, Dice *dice);
  void setTimerCooldown(float cooldown);
};