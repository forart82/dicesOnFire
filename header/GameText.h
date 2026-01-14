#pragma once

#include <SFML/Graphics.hpp>
#include <map>

class GameText
{

private:
  sf::Text m_sfText;
  sf::Font m_sfFont;
  bool m_isFontLoaded;
  std::map<std::string, std::string> m_texts;

public:
  GameText();
  GameText(std::string text);
  GameText(std::string text, sf::Vector2f position);
  GameText(std::string text, sf::Vector2f position, sf::Color color);
  GameText(std::string key, std::string text, sf::Vector2f position, sf::Color color);
  ~GameText();

  void draw(sf::RenderWindow &window);

  void init(std::string key, std::string text, sf::Vector2f position, sf::Color color);
  void addText(std::string key, std::string text);
  void removeText();
  void setPosition(sf::Vector2f position);
  void setColor(sf::Color color);
  sf::Text getSfText();
  std::map<std::string, std::string> getTexts();
};
