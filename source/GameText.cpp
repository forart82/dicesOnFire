#include "../header/GameText.h"
#include "../header/_GLOBALS.h"

GameText::GameText() : GameText("", "", {10, 10}, COLOR_SKY_BLUE)
{
}

GameText::GameText(std::string text)
    : GameText("", text, {10, 10}, COLOR_SKY_BLUE)
{
}

GameText::GameText(std::string text, sf::Vector2f position)
    : GameText("", "", position, COLOR_SKY_BLUE)
{
}

GameText::GameText(std::string text, sf::Vector2f position, sf::Color color)
    : GameText("", "", position, color)
{
}

GameText::GameText(std::string key, std::string text, sf::Vector2f position, sf::Color color) : m_sfText(m_sfFont)
{
  if (!this->m_sfFont.openFromFile("arial.ttf"))
  {
    throw std::runtime_error("FATAL ERROR: Could not load font 'arial.ttf' for GameText.");
  }
  this->m_sfText.setPosition(position);
  this->m_sfText.setFillColor(color);
}

GameText::~GameText()
{
}

void GameText::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(this->m_sfText, states);
}

void GameText::addText(std::string key, std::string value)
{
  this->m_texts[key] = value;
  std::string combined;
  combined.reserve(256);
  for (auto const &[key, value] : this->m_texts)
  {
    combined += value + "\n";
  }
  this->m_sfText.setString(combined);
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

const std::map<std::string, std::string> &GameText::getTexts() const
{
  return this->m_texts;
}
