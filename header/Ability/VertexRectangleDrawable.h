#pragma once

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <initializer_list>
#include "Entity/Game.h"
#include "Helper/RandomHelper.h"
#include "Loader/ConfigLoader.h"

class VertexRectangleDrawable
{

protected:
  Game &m_game;

  int m_bodyLeft;
  int m_bodyTop;
  int m_assetLeft;
  int m_assetTop;
  int m_tileSize;
  int m_assetTileSize;

  sf::Vector2f m_bodyLeftTop;
  sf::Vector2f m_bodyRightTop;
  sf::Vector2f m_bodyLeftBottom;
  sf::Vector2f m_bodyRightBottom;

  sf::Vector2f m_assetLeftTop;
  sf::Vector2f m_assetRightTop;
  sf::Vector2f m_assetLeftBottom;
  sf::Vector2f m_assetRightBottom;

  bool m_isActive;

public:
  VertexRectangleDrawable(Game &game);
  ~VertexRectangleDrawable();

  void makeBody();
  void makeAsset();
  void makeAll();
  void toggleIsActive();

  void setBodyPosition(const sf::Vector2f &position);
  void setAssetPosition(const sf::Vector2f &position);
  void setBodyFloatRect(const sf::FloatRect &floatRect);
  void setAssetFloatRect(const sf::FloatRect &floatRect);
  void setFloatRects(sf::FloatRect &body, sf::FloatRect &asset);
  void setIsActive(bool isActive);

  const sf::FloatRect &getBody() const;
  const sf::FloatRect &getAsset() const;
  const sf::Vector2f &getBodyCenter() const;
  const sf::Vector2f &getAssetCenter() const;
  const sf::FloatRect &getGlobalBounds() const;
  bool &getIsActive() const;
};
