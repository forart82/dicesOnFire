#include "GameText.h"
#include "Manager/FontManager.h"
#include "_GLOBALS.h"
#include "_COLORS.h"

GameText::GameText() : GameText("", "", {10, 10}, colors::COLOR_BLUE_SKY_BLUE, "Quantico")
{
}

GameText::GameText(
    std::string key,
    std::string text,
    sf::Vector2f position,
    sf::Color color,
    std::string fontName)
    : m_sfText(fontManager::get(fontName))
{
  m_sfText.setPosition(position);
  m_sfText.setFillColor(color);
}

GameText::~GameText()
{
}

void GameText::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(m_sfText, states);
}

void GameText::addText(std::string key, std::string value)
{
  m_texts[key] = value;
  std::string combined;
  combined.reserve(1024);
  for (auto const &[key, value] : m_texts)
  {
    combined += value + "\n";
  }
  m_sfText.setString(combined);
}

void GameText::removeText()
{
  m_texts.clear();
}

void GameText::setPosition(sf::Vector2f position)
{
  m_sfText.setPosition(position);
}

void GameText::setColor(sf::Color color)
{
  m_sfText.setFillColor(color);
}

void GameText::setFontSize(int fontSize)
{
  m_sfText.setCharacterSize(fontSize);
}

sf::Text GameText::getSfText()
{
  return m_sfText;
}

const std::map<std::string, std::string> &GameText::getTexts() const
{
  return m_texts;
}
