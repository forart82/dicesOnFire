#pragma once

#include <map>

#include "Loader/BaseLoader.h"

class TextureLoader : public BaseLoader
{
private:
  std::map<std::string, sf::Texture> m_textures;

public:
  TextureLoader();
  ~TextureLoader();

  bool load(const std::string &name, const std::string &filename);
  void loadAll();
  void reload();
  const sf::Texture &getTexture(const std::string &name);
  const sf::IntRect &getTileRect(int tileX, int tileY, int tileSize) const;
};