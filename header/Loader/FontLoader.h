#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

#include "Loader/BaseLoader.h"

class FontLoader : public BaseLoader
{
private:
  std::map<std::string, sf::Font> m_fonts;

public:
  FontLoader();
  ~FontLoader();

  void load(const std::string &name, const std::string &path);
  void loadAll();
  void reload();
  const sf::Font &get(std::string name);
};