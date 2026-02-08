#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "Loader/FontLoader.h"
#include "Globals/Colors.h"

class GameText : public sf::Drawable
{

private:
  sf::Text m_sfText;
  std::map<std::string, std::string> m_texts;

public:
  GameText();
  GameText(std::string key, std::string text, sf::Vector2f position, sf::Color color, std::string fontName);
  ~GameText();

  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void addText(std::string key, std::string text);
  void removeText();
  void setPosition(sf::Vector2f position);
  void setColor(sf::Color color);
  void setFontSize(int fontSize);
  sf::Text getSfText();
  const std::map<std::string, std::string> &getTexts() const;
};
