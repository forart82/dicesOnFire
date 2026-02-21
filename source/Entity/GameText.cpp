#include "Entity/GameText.h"

GameText::GameText(Game &game)
    : m_game(game),
      m_sfText(fontLoader::get("Quantico"))
{
  m_sfText.setFillColor(colors::COLOR_BLUE_SKY_BLUE);
}

GameText::~GameText()
{
}

void GameText::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(m_sfText, states);
}

void GameText::addText(const std::string &key, const std::string &value)
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

void GameText::setPosition(const sf::Vector2f &position)
{
  m_sfText.setPosition(position);
}

void GameText::setColor(const sf::Color &color)
{
  m_sfText.setFillColor(color);
}

void GameText::setFontSize(int fontSize)
{
  m_sfText.setCharacterSize(fontSize);
}

const sf::Text &GameText::getSfText() const
{
  return m_sfText;
}

const std::map<std::string, std::string> &GameText::getTexts() const
{
  return m_texts;
}
