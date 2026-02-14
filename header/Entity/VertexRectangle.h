#pragma once

#include <SFML/Graphics.hpp>
#include "Helper/RandomHelper.h"
#include "Loader/ConfigLoader.h"

class VertexRectangle
{

protected:
  int m_left;
  int m_top;
  int m_assetsLeft;
  int m_assetsTop;
  int m_tileSize;
  int m_assetsTileSize;

  sf::Vector2f m_leftTop;
  sf::Vector2f m_rightTop;
  sf::Vector2f m_leftBottom;
  sf::Vector2f m_rightBottom;

  sf::Vector2f m_assetsLeftTop;
  sf::Vector2f m_assetsRightTop;
  sf::Vector2f m_assetsLeftBottom;
  sf::Vector2f m_assetsRightBottom;

public:
  VertexRectangle(
      int left,
      int top,
      int assetsLeft,
      int assetsTop)
      : m_left(left),
        m_top(top),
        m_assetsLeft(assetsLeft),
        m_assetsTop(assetsTop),
        m_tileSize(configLoader::get<int>("TILE_SIZE")),
        m_assetsTileSize(configLoader::get<int>("ASSETS_TILE_SIZE"))
  {
    makeAllCorners();
  }

  ~VertexRectangle() {}

  void resetLeftTop(sf::Vector2f leftTop)
  {
    m_left = leftTop.x;
    m_top = leftTop.y;
    makeAllCorners();
  }

  void makeAllCorners()
  {
    m_leftTop = sf::Vector2f(m_left, m_top);
    m_rightTop = sf::Vector2f(m_left + m_tileSize, m_top);
    m_leftBottom = sf::Vector2f(m_left, m_top + m_tileSize);
    m_rightBottom = sf::Vector2f(m_left + m_tileSize, m_top + m_tileSize);

    m_assetsLeftTop = sf::Vector2f(m_assetsLeft, m_assetsTop);
    m_assetsRightTop = sf::Vector2f(m_assetsLeft + m_assetsTileSize, m_assetsTop);
    m_assetsLeftBottom = sf::Vector2f(m_assetsLeft, m_assetsTop + m_assetsTileSize);
    m_assetsRightBottom = sf::Vector2f(m_assetsLeft + m_assetsTileSize, m_assetsTop + m_assetsTileSize);
  }

  sf::Vector2f &getLeftTop()
  {
    return m_leftTop;
  }

  sf::Vector2f &getRightTop()
  {
    return m_rightTop;
  }

  sf::Vector2f &getLeftBottom()
  {
    return m_leftBottom;
  }

  sf::Vector2f &getRightBottom()
  {
    return m_rightBottom;
  }

  sf::Vector2f &getAssetsLeftTop()
  {
    return m_assetsLeftTop;
  }

  sf::Vector2f &getAssetsRightTop()
  {
    return m_assetsRightTop;
  }

  sf::Vector2f &getAssetsLeftBottom()
  {
    return m_assetsLeftBottom;
  }

  sf::Vector2f &getAssetsRightBottom()
  {
    return m_assetsRightBottom;
  }
};
