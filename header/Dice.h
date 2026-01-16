#pragma once

#include <SFML/Graphics.hpp>
#include "Timer.h"
#include "GameText.h"
#include <map>

class Dice : public sf::Drawable, sf::Transform
{
private:
  sf::CircleShape m_slot;
  GameText m_faceValueText;
  Timer m_timer;
  int m_faces;
  int m_rerolls;
  std::map<int, float> m_faceValues;

public:
  Dice();
  Dice(int faces, int rerolls, sf::Vector2f position, sf::Vector2f size, sf::Color);

  ~Dice();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};