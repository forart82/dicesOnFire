#include "../header/GameText.h"
#include "../header/_GLOBALS.h"

GameText::GameText() : m_sfText(m_sfFont), m_isFontLoaded(false)
{
  this->init("", {10, 10}, COLOR_SKY_BLUE);
}

GameText::GameText(std::string text) : m_sfText(m_sfFont), m_isFontLoaded(false)
{
  this->init(text, {10, 10}, COLOR_SKY_BLUE);
}

GameText::GameText(std::string text, sf::Vector2f position) : m_sfText(m_sfFont), m_isFontLoaded(false)
{
  this->init(text, position, COLOR_SKY_BLUE);
}

GameText::GameText(std::string text, sf::Vector2f position, sf::Color color) : m_sfText(m_sfFont), m_isFontLoaded(false)
{
  this->init(text, position, color);
}

GameText::~GameText()
{
}

void GameText::init(std::string text, sf::Vector2f position, sf::Color color)
{
  this->m_isFontLoaded = m_sfFont.openFromFile("arial.ttf");
  if (!this->m_isFontLoaded)
  {
    throw std::runtime_error("FATAL ERROR: Could not load font 'arial.ttf' for GameText.");
  }
  this->m_text = text;
  this->m_sfText.setPosition(position);
  this->m_sfText.setFillColor(color);
}

void GameText::addText(std::string text)
{
  this->m_text = text;
  this->m_sfText.setString(this->m_text);
}

void GameText::setPosition(sf::Vector2f position)
{
  this->m_sfText.setPosition(position);
}
void GameText::setColor(sf::Color color)
{
  this->m_sfText.setFillColor(color);
}
sf::Text GameText::getSfText()
{
  return this->m_sfText;
}

std::string GameText::getText()
{
  return this->m_text;
}
