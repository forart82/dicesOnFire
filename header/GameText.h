#pragma once

#include <SFML/Graphics.hpp>

class GameText
{

private:
  sf::Text m_sfText;
  sf::Font m_sfFont;
  bool m_isFontLoaded;
  std::string m_text;

public:
  GameText();
  GameText(std::string text);
  GameText(std::string text, sf::Vector2f position);
  GameText(std::string text, sf::Vector2f position, sf::Color color);
  ~GameText();

  void init(std::string text, sf::Vector2f position, sf::Color color);
  void addText(std::string text);
  void setPosition(sf::Vector2f position);
  void setColor(sf::Color color);
  sf::Text getSfText();
  std::string getText();
};
