#pragma once;

#include <SFML/Graphics.hpp>
#include <list>
#include "Dice.h"

class DiceBox
{

private:
  std::list<Dice> m_dices;
  sf::Vector2f m_position;
  sf::Vector2f m_size;
  sf::Color m_backgroundColor;
  sf::RectangleShape background;

public:
  DiceBox();
  DiceBox(sf::Vector2f position, sf::Vector2f size, sf::Color backgroundColor);
  ~DiceBox();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};