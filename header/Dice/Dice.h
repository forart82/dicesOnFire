#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <random>
#include "GameText.h"
#include "Timer.h"
#include "Form/BaseCircle.h"

class Dice : public BaseCircle
{
private:
  BaseCircle m_diceMenu;
  std::unique_ptr<GameText> m_diceValueText;
  Timer m_timer;
  std::map<int, float> m_faceValues;
  int m_rerolls;
  int m_faces;
  float m_padding;
  bool m_stop;
  sf::Time m_elapsedTime;

public:
  Dice();
  Dice(BaseCircle diceMenu, int faces, int rerolls, float cooldown);

  ~Dice();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void makeFaceValues();
  void handelTextPositionBasedOnDiceValue(int diceValues);
  void toggleStop();

  void setFaces(int faces);
  void setRerolls(int rerolls);
  void setCooldown(float cooldown);
  void setFaceValues(std::map<int, float> faceValues);

  void onTimeout();

  float roll();
};