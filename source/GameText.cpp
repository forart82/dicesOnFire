#include "../header/GameText.h"
#include "../header/_GLOBALS.h"

GameText::GameText() : m_sfText(m_sfFont), m_isFontLoaded(false)
{
  this->init("", "", {10, 10}, COLOR_SKY_BLUE);
}

GameText::GameText(std::string text) : m_sfText(m_sfFont), m_isFontLoaded(false)
{
  this->init("", text, {10, 10}, COLOR_SKY_BLUE);
}

GameText::GameText(std::string text, sf::Vector2f position) : m_sfText(m_sfFont), m_isFontLoaded(false)
{
  this->init("", text, position, COLOR_SKY_BLUE);
}

GameText::GameText(std::string text, sf::Vector2f position, sf::Color color) : m_sfText(m_sfFont), m_isFontLoaded(false)
{
  this->init("", text, position, color);
}

GameText::GameText(std::string key, std::string text, sf::Vector2f position, sf::Color color) : m_sfText(m_sfFont), m_isFontLoaded(false)
{
  this->init(key, text, position, color);
}

GameText::~GameText()
{
}

void GameText::draw(sf::RenderWindow &window)
{
  window.draw(this->m_sfText);
  this->removeText();
}

void GameText::init(std::string key, std::string text, sf::Vector2f position, sf::Color color)
{
  this->m_isFontLoaded = m_sfFont.openFromFile("arial.ttf");
  if (!this->m_isFontLoaded)
  {
    throw std::runtime_error("FATAL ERROR: Could not load font 'arial.ttf' for GameText.");
  }
  this->m_sfText.setPosition(position);
  this->m_sfText.setFillColor(color);
}

void GameText::addText(std::string key, std::string value)
{
  this->m_texts[key] = value;
  std::string tmp = "";
  for (auto const &[key, value] : this->m_texts)
  {
    tmp += value + "\n";
  }
  this->m_sfText.setString(tmp);
}

void GameText::removeText()
{
  this->m_texts.clear();
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

std::map<std::string, std::string> GameText::getTexts()
{
  return this->m_texts;
}
