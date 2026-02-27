#pragma once

#include "Entity/Game.h"
#include "Entity/BaseEntity.h"
#include "Loader/FontLoader.h"
#include "Globals/Colors.h"

class GameText : public BaseEntity, public sf::Drawable
{

private:
  sf::Text m_sfText;
  std::map<std::string, std::string> m_texts;

public:
  GameText();
  ~GameText();

  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void addText(const std::string &key, const std::string &text);
  void removeText();

  void setPosition(const sf::Vector2f &position);
  void setColor(const sf::Color &color);
  void setFontSize(int fontSize);

  const sf::Text &getSfText() const;
  const std::map<std::string, std::string> &getTexts() const;
};
