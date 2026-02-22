#pragma once

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <initializer_list>

class VertexRectangleDrawable
{

protected:
  int m_vertexBodyLeft;
  int m_vertexBodyTop;

  int m_vertexAssetBodyLeft;
  int m_vertexAssetBodyTop;

  int m_tileSize;
  int m_assetTileSize;

  sf::Vector2f m_vertexBodyLeftTop;
  sf::Vector2f m_vertexBodyRightTop;
  sf::Vector2f m_vertexBodyLeftBottom;
  sf::Vector2f m_vertexBodyRightBottom;

  sf::Vector2f m_vertexAssetBodyLeftTop;
  sf::Vector2f m_vertexAssetBodyRightTop;
  sf::Vector2f m_vertexAssetBodyLeftBottom;
  sf::Vector2f m_vertexAssetBodyRightBottom;

  bool m_isActive;

public:
  VertexRectangleDrawable();
  ~VertexRectangleDrawable();

  void makeVertexBody();
  void makeVertexAssetBody();
  void makeAll();
  void toggleIsActive();

  void setVertexBodyPosition(const sf::Vector2f &position);
  void setVertexAssetBodyPosition(const sf::Vector2f &position);
  void setVertexBodyFloatRect(const sf::FloatRect &floatRect);
  void setVertexAssetBodyFloatRect(const sf::FloatRect &floatRect);
  void setFloatRects(sf::FloatRect &vertexBody, sf::FloatRect &vertexAssetBody);
  void setTileSize(int tileSize);
  void setAssetTileSize(int assetTileSize);
  void setIsActive(bool isActive);

  const sf::FloatRect &getVertexBody() const;
  const sf::FloatRect &getVertexAssetBody() const;
  const sf::Vector2f &getVertexBodyCenter() const;
  const sf::Vector2f &getVertexAssetBodyCenter() const;
  const sf::FloatRect &getGlobalBounds() const;
  bool getIsActive() const;
};
