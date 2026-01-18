#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "Timer.h"
#include "Dice.h"

class DiceBox : public sf::Drawable
{

private:
  std::map<int, Dice *> m_dices;
  std::unique_ptr<Timer> m_timer;
  sf::Vector2f m_position;
  sf::Vector2f m_size;
  sf::Color m_backgroundColor;
  sf::RectangleShape m_boxShape;
  float m_cooldown;

public:
  DiceBox();
  DiceBox(sf::Vector2f position, sf::Vector2f size, sf::Color backgroundColor, float clooldown);
  ~DiceBox();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void addDice(int slotNumber, Dice *dice);
  void setTimerCooldown(float cooldown);
};