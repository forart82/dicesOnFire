#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <random>
#include "GameText.h"
#include "Timer.h"
#include "Form/BaseCircle.h"
#include "_HELPERS.h"
#include "Vertex/VertexRectangle.h"

class Dice : public sf::Drawable, public VertexRectangle
{
private:
  BaseCircle m_diceWeaponSlotMenu;
  BaseCircle m_diceSacMenu;
  BaseCircle m_diceFloorItem;

  std::unique_ptr<GameText> m_diceValueText;
  int m_faces;
  std::map<int, float> m_faceValues;
  int m_rerolls;

  Timer m_timer;
  sf::Time m_elapsedTime;

  bool m_stop;
  bool m_isOnFloor;

public:
  Dice();
  Dice(int faces, int rerolls, float cooldown);

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
  void setIsOnFloor(bool isOnFloor);

  void onTimeout();
};