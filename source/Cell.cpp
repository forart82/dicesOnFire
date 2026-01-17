#include "../header/Cell.h"
#include <SFML/Graphics.hpp>
#include "../header/_GLOBALS.h"
#include "../header/_HELPERS.h"
#include <iostream>

using namespace std;

Cell::Cell(
    sf::Vertex *rect,
    sf::Vector2f position,
    sf::Color color)
    : m_rect(rect),
      m_position(position),
      m_color(color),
      m_top(position.y),
      m_left(position.x + TILE_SIZE),
      m_bottom(position.y + TILE_SIZE),
      m_right(position.x),
      m_key(MAKE_CELL_KEY(m_top, m_right, m_bottom, m_left))
{
  manageCell(rect, position);
}

Cell::~Cell()
{
}

void Cell::update()
{
}

void Cell::manageCell(sf::Vertex *rect, sf::Vector2f position)
{
  setPosition(position);
  setKey();
  setTriangles(rect);
  setRectColor();
}

// MARK: Setter
void Cell::setPosition(sf::Vector2f position)
{
  m_position = position;

  // Update the vertex positions
  m_top = SNAP_TO_GRID(position.y);
  m_right = SNAP_TO_GRID(position.x + TILE_SIZE);
  m_bottom = SNAP_TO_GRID(position.y + TILE_SIZE);
  m_left = SNAP_TO_GRID(position.x);
}
void Cell::setKey()
{
  m_key = MAKE_CELL_KEY(m_top, m_right, m_bottom, m_left);
}

void Cell::setTriangles(sf::Vertex *rect)
{
  m_rect = rect;

  // Define the 4 corners of the quad
  sf::Vector2f topLeft(m_left + GAP_SIZE, m_top + GAP_SIZE);
  sf::Vector2f topRight(m_right - GAP_SIZE, m_top + GAP_SIZE);
  sf::Vector2f bottomLeft(m_left + GAP_SIZE, m_bottom - GAP_SIZE);
  sf::Vector2f bottomRight(m_right - GAP_SIZE, m_bottom - GAP_SIZE);

  // Define the 2 triangles that make up the quad
  // Triangle 1
  m_rect[0].position = topLeft;
  m_rect[1].position = topRight;
  m_rect[2].position = bottomLeft;
  // Triangle 2
  m_rect[3].position = topRight;
  m_rect[4].position = bottomRight;
  m_rect[5].position = bottomLeft;
}

void Cell::setRectColor()
{
  if (m_rect != nullptr)
  {
    for (int i = 0; i < 6; ++i)
    {
      m_rect[i].color = m_color;
    }
  }
}

void Cell::setColor(sf::Color color)
{
  m_color = color;
}

// MARK: Getter

std::string Cell::getKey() const
{
  return m_key;
}

sf::Color Cell::getColor()
{
  return m_color;
}

sf::Vector2f Cell::getPosition() const
{
  return m_position;
}