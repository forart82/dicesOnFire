#pragma once

#include <SFML/Graphics.hpp>
#include "_HELPERS.h"
#include "_GLOBALS.h"

class VertexRectangle
{

protected:
  int m_left;
  int m_top;
  int m_assetsLeft;
  int m_assetsTop;

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
        m_assetsLeftTop(assetsTop)
  {
    m_leftTop = sf::Vector2f(m_left, m_top);
    m_rightTop = sf::Vector2f(m_left + TILE_SIZE, m_top);
    m_leftBottom = sf::Vector2f(m_left, m_top + TILE_SIZE);
    m_rightBottom = sf::Vector2f(m_left + TILE_SIZE, m_top + TILE_SIZE);

    m_assetsLeftTop = sf::Vector2f(m_assetsLeft, m_assetsTop);
    m_assetsRightTop = sf::Vector2f(m_assetsLeft + ASSETS_TILE_SIZE, m_assetsTop);
    m_assetsLeftBottom = sf::Vector2f(m_assetsLeft, m_assetsTop + ASSETS_TILE_SIZE);
    m_assetsRightBottom = sf::Vector2f(m_assetsLeft + ASSETS_TILE_SIZE, m_assetsTop + ASSETS_TILE_SIZE);
  }
  ~VertexRectangle();

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
