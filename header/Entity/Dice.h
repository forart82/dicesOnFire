#pragma once

#include <SFML/Graphics.hpp>
#include "Ability/Dragable.h"
#include "Ability/Hoverable.h"
#include "Ability/PickUpable.h"
#include "Ability/VertexRectangleDrawable.h"
#include "Entity/BaseEntity.h"
#include "Entity/GameText.h"
#include "Entity/Timer.h"
#include "Entity/Circle.h"
#include "Helper/RandomHelper.h"
#include "Loader/ConfigLoader.h"
#include "Loader/RandomNameLoader.h"

class Dice
    : public BaseEntity,
      public sf::Drawable,
      public Dragable,
      public Hoverable,
      public PickUpable,
      public VertexRectangleDrawable
{
private:
  std::unique_ptr<Timer> m_timer;

  std::map<int, float> m_faceValues;
  std::string m_name;

  size_t m_faces;
  int m_rerolls;

  bool m_isOnFloor;

  // TO REMOVE
  // Is only there for auto restart the timer
  // but the mecanic must be a event like action
  sf::Time m_elapsedTime;

public:
  Dice();
  ~Dice();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void makeFaceValues();

  void setFaces(size_t faces);
  void setRerolls(int rerolls);
  void setCooldown(float cooldown);
  void setFaceValues(const std::map<int, float> &faceValues);
  void setIsOnFloor(bool isOnFloor);
  void setPosition(const sf::Vector2f &position);

  void onTimeout();

  const std::string &getName() const;
  const std::string &getStats() const;

  const sf::FloatRect &getGlobalBounds() const;
  const sf::Vector2f &getPosition() const;
};