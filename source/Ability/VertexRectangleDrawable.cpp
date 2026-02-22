#include "Ability/VertexRectangleDrawable.h"

VertexRectangleDrawable::VertexRectangleDrawable()
    : m_game(game),
      m_vertexBodyLeft(0),
      m_vertexBodyTop(0),
      m_vertexAssetBodyLeft(0),
      m_vertexAssetBodyTop(0),
      m_tileSize(configLoader::get<int>("TILE_SIZE")),
      m_assetTileSize(configLoader::get<int>("ASSET_TILE_SIZE")),
      m_isActive(true)
{
  makeAll();
}

VertexRectangleDrawable::~VertexRectangleDrawable() {}

void VertexRectangleDrawable::makeVertexBody()
{
  m_vertexBodyLeftTop = sf::Vector2f(m_vertexBodyLeft, m_vertexBodyTop);
  m_vertexBodyRightTop = sf::Vector2f(m_vertexBodyLeft + m_tileSize, m_vertexBodyTop);
  m_vertexBodyLeftBottom = sf::Vector2f(m_vertexBodyLeft, m_vertexBodyTop + m_tileSize);
  m_vertexBodyRightBottom = sf::Vector2f(m_vertexBodyLeft + m_tileSize, m_vertexBodyTop + m_tileSize);
}
void VertexRectangleDrawable::makeVertexAssetBody()
{
  m_vertexAssetBodyLeftTop = sf::Vector2f(m_vertexAssetBodyLeft, m_vertexAssetBodyTop);
  m_vertexAssetBodyRightTop = sf::Vector2f(m_vertexAssetBodyLeft + m_assetTileSize, m_vertexAssetBodyTop);
  m_vertexAssetBodyLeftBottom = sf::Vector2f(m_vertexAssetBodyLeft, m_vertexAssetBodyTop + m_assetTileSize);
  m_vertexAssetBodyRightBottom = sf::Vector2f(m_vertexAssetBodyLeft + m_assetTileSize, m_vertexAssetBodyTop + m_assetTileSize);
}

void VertexRectangleDrawable::makeAll()
{
  makeVertexBody();
  makeVertexAssetBody();
}

void VertexRectangleDrawable::toggleIsActive()
{
  m_isActive = !m_isActive;
}

void VertexRectangleDrawable::setVertexBodyPosition(const sf::Vector2f &position)
{
  m_vertexBodyLeft = position.x;
  m_vertexBodyTop = position.y;
  makeVertexBody();
}

void VertexRectangleDrawable::setVertexAssetBodyPosition(const sf::Vector2f &position)
{
  m_vertexAssetBodyLeft = position.x;
  m_vertexAssetBodyTop = position.y;
  makeVertexAssetBody();
}

void VertexRectangleDrawable::setVertexBodyFloatRect(const sf::FloatRect &floatRect)
{
  m_vertexBodyLeftTop = sf::Vector2f(floatRect.position.x, floatRect.position.y);
  m_vertexBodyRightTop = sf::Vector2f(floatRect.size.x, floatRect.position.y);
  m_vertexBodyLeftBottom = sf::Vector2f(floatRect.position.x, floatRect.size.y);
  m_vertexBodyRightBottom = sf::Vector2f(floatRect.size.x, floatRect.size.y);
}

void VertexRectangleDrawable::setVertexAssetBodyFloatRect(const sf::FloatRect &floatRect)
{
  m_vertexAssetBodyLeftTop = sf::Vector2f(floatRect.position.x, floatRect.position.y);
  m_vertexAssetBodyRightTop = sf::Vector2f(floatRect.size.x, floatRect.position.y);
  m_vertexAssetBodyLeftBottom = sf::Vector2f(floatRect.position.x, floatRect.size.y);
  m_vertexAssetBodyRightBottom = sf::Vector2f(floatRect.size.x, floatRect.size.y);
}

void VertexRectangleDrawable::setFloatRects(sf::FloatRect &vertexBody, sf::FloatRect &asset)
{
  setVertexBodyFloatRect(vertexBody);
  setVertexAssetBodyFloatRect(asset);
}

void VertexRectangleDrawable::setIsActive(bool isActive)
{
  m_isActive = isActive;
}

const sf::FloatRect &VertexRectangleDrawable::getVertexBody() const
{
  return sf::FloatRect({m_vertexBodyLeftTop.x, m_vertexBodyLeftTop.y}, {m_vertexBodyRightBottom.x, m_vertexBodyRightBottom.y});
}

const sf::FloatRect &VertexRectangleDrawable::getVertexAssetBody() const
{
  return sf::FloatRect({m_vertexAssetBodyLeftTop.x, m_vertexAssetBodyLeftTop.y}, {m_vertexAssetBodyRightBottom.x, m_vertexAssetBodyRightBottom.y});
}

const sf::Vector2f &VertexRectangleDrawable::getVertexBodyCenter() const
{
  return (m_vertexBodyLeftTop + m_vertexBodyRightBottom) / 2.f;
}
const sf::Vector2f &VertexRectangleDrawable::getVertexAssetBodyCenter() const
{
  return (m_vertexAssetBodyLeftTop + m_vertexAssetBodyRightBottom) / 2.f;
}

const sf::FloatRect &VertexRectangleDrawable::getGlobalBounds() const
{
  // 1. Find the Minimum X and Y (The Top-Left of the bounding box)
  float minX = std::min({m_vertexBodyLeftTop.x, m_vertexBodyRightTop.x, m_vertexBodyLeftBottom.x, m_vertexBodyRightBottom.x});
  float minY = std::min({m_vertexBodyLeftTop.y, m_vertexBodyRightTop.y, m_vertexBodyLeftBottom.y, m_vertexBodyRightBottom.y});

  // 2. Find the Maximum X and Y (The Bottom-Right of the bounding box)
  float maxX = std::max({m_vertexBodyLeftTop.x, m_vertexBodyRightTop.x, m_vertexBodyLeftBottom.x, m_vertexBodyRightBottom.x});
  float maxY = std::max({m_vertexBodyLeftTop.y, m_vertexBodyRightTop.y, m_vertexBodyLeftBottom.y, m_vertexBodyRightBottom.y});

  // 3. Calculate Width and Height
  float width = maxX - minX;
  float height = maxY - minY;

  // 4. Return the Rectangle
  return sf::FloatRect({minX, minY}, {width, height});
}

bool VertexRectangleDrawable::getIsActive() const
{
  return m_isActive;
}