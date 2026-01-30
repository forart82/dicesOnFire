#pragma once

#include <SFML/Graphics.hpp>

class Cell
{

private:
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
  Cell(int left, int top);
  ~Cell();

  sf::Vector2f &getLeftTop();
  sf::Vector2f &getRightTop();
  sf::Vector2f &getLeftBottom();
  sf::Vector2f &getRightBottom();

  sf::Vector2f &getAssetsLeftTop();
  sf::Vector2f &getAssetsRightTop();
  sf::Vector2f &getAssetsLeftBottom();
  sf::Vector2f &getAssetsRightBottom();
};
