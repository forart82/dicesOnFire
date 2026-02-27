#include "Loader/TextureLoader.h"

TextureLoader::TextureLoader() {}
TextureLoader::~TextureLoader() {}

bool TextureLoader::load(const std::string &name, const std::string &filename)
{
  sf::Texture tex;
  if (tex.loadFromFile(filename))
  {
    m_textures[name] = tex;
    return true;
  }
  return false;
}

void TextureLoader::loadAll()
{
  load("Utumno", "assets/images/ProjectUtumno_full.png");
}

void TextureLoader::reload()
{
  m_textures.clear();
  loadAll();
}

const sf::Texture &TextureLoader::getTexture(const std::string &name)
{
  if (m_textures.empty())
  {
    loadAll();
  }
  return m_textures.at(name);
}

const sf::IntRect &TextureLoader::getTileRect(int tileX, int tileY, int tileSize) const
{
  return sf::IntRect({tileX * tileSize, tileY * tileSize}, {tileSize, tileSize});
}
