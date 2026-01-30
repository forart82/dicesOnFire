#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cell.h"
#include "_GLOBALS.h"
#include "_HELPERS.h"
#include "Manager/TextureManager.h"

using namespace std;

Cell::Cell(int left, int top)
{
  m_left = left;
  m_top = top;

  m_assetsLeft = 32 * GET_RANDOM_NUMBER_INT(0, 10);
  m_assetsTop = 224;

  m_leftTop = sf::Vector2f(m_left, m_top);
  m_rightTop = sf::Vector2f(m_left + TILE_SIZE, m_top);
  m_leftBottom = sf::Vector2f(m_left, m_top + TILE_SIZE);
  m_rightBottom = sf::Vector2f(m_left + TILE_SIZE, m_top + TILE_SIZE);

  m_assetsLeftTop = sf::Vector2f(m_assetsLeft, m_assetsTop);
  m_assetsRightTop = sf::Vector2f(m_assetsLeft + ASSETS_TILE_SIZE, m_assetsTop);
  m_assetsLeftBottom = sf::Vector2f(m_assetsLeft, m_assetsTop + ASSETS_TILE_SIZE);
  m_assetsRightBottom = sf::Vector2f(m_assetsLeft + ASSETS_TILE_SIZE, m_assetsTop + ASSETS_TILE_SIZE);
}

Cell::~Cell() {}

sf::Vector2f &Cell::getLeftTop()
{
  return m_leftTop;
}

sf::Vector2f &Cell::getRightTop()
{
  return m_rightTop;
}

sf::Vector2f &Cell::getLeftBottom()
{
  return m_leftBottom;
}

sf::Vector2f &Cell::getRightBottom()
{
  return m_rightBottom;
}

sf::Vector2f &Cell::getAssetsLeftTop()
{
  return m_assetsLeftTop;
}

sf::Vector2f &Cell::getAssetsRightTop()
{
  return m_assetsRightTop;
}

sf::Vector2f &Cell::getAssetsLeftBottom()
{
  return m_assetsLeftBottom;
}

sf::Vector2f &Cell::getAssetsRightBottom()
{
  return m_assetsRightBottom;
}
