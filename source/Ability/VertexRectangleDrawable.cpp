#include "Ability/VertexRectangleDrawable.h"

VertexRectangleDrawable::VertexRectangleDrawable(Game &game)
    : m_game(game),
      m_bodyLeft(0),
      m_bodyTop(0),
      m_assetLeft(0),
      m_assetTop(0),
      m_tileSize(configLoader::get<int>("TILE_SIZE")),
      m_assetTileSize(configLoader::get<int>("ASSET_TILE_SIZE")),
      m_isActive(true)
{
  makeAll();
}

VertexRectangleDrawable::~VertexRectangleDrawable() {}

void VertexRectangleDrawable::makeBody()
{
  m_bodyLeftTop = sf::Vector2f(m_bodyLeft, m_bodyTop);
  m_bodyRightTop = sf::Vector2f(m_bodyLeft + m_tileSize, m_bodyTop);
  m_bodyLeftBottom = sf::Vector2f(m_bodyLeft, m_bodyTop + m_tileSize);
  m_bodyRightBottom = sf::Vector2f(m_bodyLeft + m_tileSize, m_bodyTop + m_tileSize);
}
void VertexRectangleDrawable::makeAsset()
{
  m_assetLeftTop = sf::Vector2f(m_assetLeft, m_assetTop);
  m_assetRightTop = sf::Vector2f(m_assetLeft + m_assetTileSize, m_assetTop);
  m_assetLeftBottom = sf::Vector2f(m_assetLeft, m_assetTop + m_assetTileSize);
  m_assetRightBottom = sf::Vector2f(m_assetLeft + m_assetTileSize, m_assetTop + m_assetTileSize);
}

void VertexRectangleDrawable::makeAll()
{
  makeBody();
  makeAsset();
}

void VertexRectangleDrawable::toggleIsActive()
{
  m_isActive = !m_isActive;
}

void VertexRectangleDrawable::setBodyPosition(const sf::Vector2f &position)
{
  m_bodyLeft = position.x;
  m_bodyTop = position.y;
  makeBody();
}

void VertexRectangleDrawable::setAssetPosition(const sf::Vector2f &position)
{
  m_assetLeft = position.x;
  m_assetTop = position.y;
  makeAsset();
}

void VertexRectangleDrawable::setBodyFloatRect(const sf::FloatRect &floatRect)
{
  m_bodyLeftTop = sf::Vector2f(floatRect.position.x, floatRect.position.y);
  m_bodyRightTop = sf::Vector2f(floatRect.size.x, floatRect.position.y);
  m_bodyLeftBottom = sf::Vector2f(floatRect.position.x, floatRect.size.y);
  m_bodyRightBottom = sf::Vector2f(floatRect.size.x, floatRect.size.y);
}

void VertexRectangleDrawable::setAssetFloatRect(const sf::FloatRect &floatRect)
{
  m_assetLeftTop = sf::Vector2f(floatRect.position.x, floatRect.position.y);
  m_assetRightTop = sf::Vector2f(floatRect.size.x, floatRect.position.y);
  m_assetLeftBottom = sf::Vector2f(floatRect.position.x, floatRect.size.y);
  m_assetRightBottom = sf::Vector2f(floatRect.size.x, floatRect.size.y);
}

void VertexRectangleDrawable::setFloatRects(sf::FloatRect &body, sf::FloatRect &asset)
{
  setBodyFloatRect(body);
  setAssetFloatRect(asset);
}

void VertexRectangleDrawable::setIsActive(bool isActive)
{
  m_isActive = isActive;
}

const sf::FloatRect &VertexRectangleDrawable::getBody() const
{
  return sf::FloatRect({m_bodyLeftTop.x, m_bodyLeftTop.y}, {m_bodyRightBottom.x, m_bodyRightBottom.y});
}

const sf::FloatRect &VertexRectangleDrawable::getAsset() const
{
  return sf::FloatRect({m_assetLeftTop.x, m_assetLeftTop.y}, {m_assetRightBottom.x, m_assetRightBottom.y});
}

const sf::Vector2f &VertexRectangleDrawable::getBodyCenter() const
{
  return (m_bodyLeftTop + m_bodyRightBottom) / 2.f;
}
const sf::Vector2f &VertexRectangleDrawable::getAssetCenter() const
{
  return (m_assetLeftTop + m_assetRightBottom) / 2.f;
}

const sf::FloatRect &VertexRectangleDrawable::getGlobalBounds() const
{
  // 1. Find the Minimum X and Y (The Top-Left of the bounding box)
  float minX = std::min({m_bodyLeftTop.x, m_bodyRightTop.x, m_bodyLeftBottom.x, m_bodyRightBottom.x});
  float minY = std::min({m_bodyLeftTop.y, m_bodyRightTop.y, m_bodyLeftBottom.y, m_bodyRightBottom.y});

  // 2. Find the Maximum X and Y (The Bottom-Right of the bounding box)
  float maxX = std::max({m_bodyLeftTop.x, m_bodyRightTop.x, m_bodyLeftBottom.x, m_bodyRightBottom.x});
  float maxY = std::max({m_bodyLeftTop.y, m_bodyRightTop.y, m_bodyLeftBottom.y, m_bodyRightBottom.y});

  // 3. Calculate Width and Height
  float width = maxX - minX;
  float height = maxY - minY;

  // 4. Return the Rectangle
  return sf::FloatRect({minX, minY}, {width, height});
}

bool &VertexRectangleDrawable::getIsActive() const
{
  return m_isActive;
}