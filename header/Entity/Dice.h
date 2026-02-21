#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <random>
#include <sstream>
#include <iomanip>
#include "Ability/Dragable.h"
#include "Entity/Game.h"
#include "Entity/GameText.h"
#include "Entity/Timer.h"
#include "Entity/Circle.h"
#include "Entity/VertexRectangle.h"
#include "Helper/RandomHelper.h"
#include "Loader/ConfigLoader.h"
#include "Loader/RandomNameLoader.h"

class Dice : public sf::Drawable, public VertexRectangle, public Dragable
{
private:
  Game &m_game;
  Circle m_diceWeaponSlotMenu;
  Circle m_diceSacMenu;
  Circle m_diceFloorItem;

  std::unique_ptr<GameText> m_diceValueText;
  int m_faces;
  std::map<int, float> m_faceValues;
  int m_rerolls;
  std::string m_name;

  Timer m_timer;
  sf::Time m_elapsedTime;

  bool m_isOnFloor;

public:
  Dice(Game &game);
  ~Dice();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void makeFaceValues();
  void handelTextPositionBasedOnDiceValue(int &diceValues);

  void setFaces(int faces);
  void setRerolls(int rerolls);
  void setCooldown(float cooldown);
  void setFaceValues(const std::map<int, float> &faceValues);
  void setIsOnFloor(bool &isOnFloor);
  void setPosition(const sf::Vector2f &position);

  void onTimeout();

  const std::string &getName() const;
  const std::string &getStats() const;

  const sf::FloatRect &getGlobalBounds() const;
  const sf::Vector2f &getPosition() const;
};