#pragma once

#include <SFML/Graphics.hpp>
#include "Timer.h"
#include "GameText.h"
#include <map>
#include <random>

class Dice : public sf::Drawable, sf::Transformable
{
private:
  sf::CircleShape m_slotShape;
  sf::CircleShape m_solideShape;
  std::unique_ptr<GameText> m_diceValueText;
  Timer m_timer;
  int m_faces;
  int m_rerolls;
  std::map<int, float> m_faceValues;
  float m_padding;
  bool m_stop;
  sf::Time m_elapsedTime;

public:
  Dice();
  Dice(int faces, int rerolls, float cooldown, sf::Vector2f position, sf::Vector2f size, sf::Color slotColor, sf::Color solideColor);

  ~Dice();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void makeFaceValues();
  void handelTextPositionBasedOnDiceValue(int diceValues);
  void toggleStop();

  void setPosition(sf::Vector2f postion);
  void setSize(sf::Vector2f size);
  void setSolideColor(sf::Color solideColor, sf::Color outlineColor);
  void setFaces(int faces);
  void setRerolls(int rerolls);
  void setCooldown(float cooldown);
  void setFaceValues(std::map<int, float> faceValues);

  void onTimeout();

  float roll();
};