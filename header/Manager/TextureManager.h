#pragma once

#include <SFML/Graphics.hpp>
#include <map>

namespace textureManager
{

  inline std::map<std::string, sf::Texture> m_textures;

  inline bool load(const std::string &name, const std::string &filename)
  {
    sf::Texture tex;
    if (tex.loadFromFile(filename))
    {
      m_textures[name] = tex;
      return true;
    }
    return false;
  }

  inline void loadAll()
  {
    load("Utumno", "assets/images/ProjectUtumno_full.png");
  }

  inline const sf::Texture &getTexture(const std::string &name)
  {
    if (m_textures.empty())
    {
      loadAll();
    }
    return m_textures.at(name);
  }

  inline sf::IntRect getTileRect(int tileX, int tileY, int tileSize)
  {
    return sf::IntRect({tileX * tileSize, tileY * tileSize}, {tileSize, tileSize});
  }
}