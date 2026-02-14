#include "Entity/DebugBar.h"

DebugBar::DebugBar(
    Hero &hero,
    Enemies &enemies)
    : m_hero(hero),
      m_enemies(enemies),
      m_isActive(false)
{
  m_textGame.setPosition(configLoader::get<Rectangle>("DEBUGBAR_TEXT_GAME").getShape().getPosition());
  m_textManager.setPosition(configLoader::get<Rectangle>("DEBUGBAR_TEXT_MANAGER").getShape().getPosition());
  m_textHero.setPosition(configLoader::get<Rectangle>("DEBUGBAR_TEXT_HERO").getShape().getPosition());
  m_textRealFps.setPosition(configLoader::get<Rectangle>("DEBUGBAR_TEXT_REALFPS").getShape().getPosition());
  m_textRealFps.setFontSize(72);
}

DebugBar::~DebugBar()
{
}

void DebugBar::update(sf::Time &delta)
{
  m_textGame.addText("fps", "Target FPS: 60");
  m_textGame.addText("fpsvalue", "FPS: " + std::to_string(1.0f / delta.asSeconds()));
  m_textGame.addText("fpsdelta", "Time since last update: " + std::to_string(delta.asSeconds()));
  m_textGame.addText("random", std::to_string(std::rand() % 100000));

  m_textManager.addText("ConfigManagerRectangles", "ConfigManager Rectangles: " + std::to_string(configLoader::m_rectangles.size()));
  m_textManager.addText("ConfigManagerRectangleX2s", "ConfigManager RectangleX2s: " + std::to_string(configLoader::m_rectangleX2s.size()));
  m_textManager.addText("ConfigManagerCircles", "ConfigManager Circles: " + std::to_string(configLoader::m_circles.size()));
  m_textManager.addText("ConfigManagerIntegers", "ConfigManager Integers: " + std::to_string(configLoader::m_integers.size()));
  m_textManager.addText("ConfigManagerFloats", "ConfigManager Floats: " + std::to_string(configLoader::m_floats.size()));
  m_textManager.addText("ConfigManagerVector2fs", "ConfigManager Vector2fs: " + std::to_string(configLoader::m_vector2fs.size()));
  m_textManager.addText("TextureManagerTextures", "TextureManager Textures: " + std::to_string(textureLoader::m_textures.size()));
  m_textManager.addText("FontManagerFonts", "FontManager Fonts: " + std::to_string(fontLoader::m_fonts.size()));

  m_textHero.addText(
      "HeroPosition",
      "Hero x: " + std::to_string(m_hero.getBody().getShape().getPosition().x) + " y: " + std::to_string(m_hero.getBody().getShape().getPosition().y));
}

void DebugBar::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if (m_isActive)
  {
    target.draw(m_debugWindow, states);
    target.draw(m_textGame, states);
    target.draw(m_textManager, states);
    target.draw(m_textHero, states);
  }
  target.draw(m_textRealFps, states);
}

void DebugBar::setRealFps(float fps)
{
  m_textRealFps.addText("RealFps", "RealFps: " + std::to_string((int)fps));
}

void DebugBar::toggleActive()
{
  m_isActive = !m_isActive;
  m_hero.toggleDebugIsActive();
  for (const auto &enemy : m_enemies.getEnemies())
  {
    enemy->toggleDebugIsActive();
  }
}
