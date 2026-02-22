#pragma once

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
  const sf::Font &get(std::string name);
};