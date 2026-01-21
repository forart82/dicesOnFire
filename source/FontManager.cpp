#include "FontManager.h"

std::map<std::string, sf::Font> FontManager::s_fonts;

void FontManager::load(std::string name, std::string path)
{
  sf::Font font;
  if (font.openFromFile(path))
  {
    s_fonts[name] = font;
  }
  else
  {
    throw std::runtime_error("Font failed to load: " + path);
  }
}

sf::Font &FontManager::get(std::string name)
{
  return s_fonts.at(name);
}