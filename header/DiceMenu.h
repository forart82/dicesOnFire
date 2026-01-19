#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "DiceBox.h"
#include "_BaseRectangle.h"

class DiceMenu : public _BaseRectangle
{

private:
  std::map<int, std::unique_ptr<DiceBox>> m_diceBoxs;
  int m_diceBoxCounter;

public:
  DiceMenu();
  DiceMenu(sf::Vector2f position, sf::Vector2f size, sf::Color fillColor, sf::Color outlineColor, bool isActive);
  ~DiceMenu();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void makeDiceBox(int diceBoxNumber);
  void makeDiceBoxes();
};