#include "Loader/FontLoader.h"

FontLoader::FontLoader() {}
FontLoader::~FontLoader() {}

void FontLoader::load(const std::string &name, const std::string &path)
{
  sf::Font font;
  if (font.openFromFile(path))
  {
    std::cout << "load: " + path << std::endl;
    m_fonts[name] = std::move(font);
  }
  else
  {
    throw std::runtime_error("Font failed to load: " + path);
  }
}

void FontLoader::loadAll()
{
  load("Arial", "assets/fonts/arial.ttf");
  load("PermanentMarker", "assets/fonts/PermanentMarker-Regular.ttf");
  load("Quantico", "assets/fonts/Quantico-Regular.ttf");
  load("SyneMono", "assets/fonts/SyneMono-Regular.ttf");
  load("Emoji", "assets/fonts/NotoEmoji-VariableFont_wght.ttf");
  load("Barcode", "assets/fonts/LibreBarcode39Extended-Regular.ttf");
  load("BarcodeText", "assets/fonts/LibreBarcode39ExtendedText-Regular.ttf");
}

void FontLoader::reload()
{
  m_fonts.clear();
  loadAll();
}

const sf::Font &FontLoader::get(std::string name)
{
  if (m_fonts.empty())
  {
    loadAll();
  }
  return m_fonts.at(name);
}