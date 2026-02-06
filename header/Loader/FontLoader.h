#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>

namespace fontLoader
{
  inline std::map<std::string, sf::Font> m_fonts;

  inline void load(const std::string &name, const std::string &path)
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

  inline void loadAll()
  {
    load("arial", "assets/fonts/arial.ttf");
    load("Pm", "assets/fonts/PermanentMarker-Regular.ttf");
    load("Quantico", "assets/fonts/Quantico-Regular.ttf");
    load("SyneMono", "assets/fonts/SyneMono-Regular.ttf");
    load("Emoji", "assets/fonts/NotoEmoji-VariableFont_wght.ttf");
    load("Barcode", "assets/fonts/LibreBarcode39Extended-Regular.ttf");
    load("BarcodeText", "assets/fonts/LibreBarcode39ExtendedText-Regular.ttf");
  }

  inline sf::Font &get(std::string name)
  {
    if (m_fonts.empty())
    {
      loadAll();
    }
    return m_fonts.at(name);
  }

}