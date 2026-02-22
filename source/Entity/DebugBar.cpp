#include "Entity/DebugBar.h"

DebugBar::DebugBar()
    : m_window(m_game->getWindow()),
      m_hero(m_game->getHero()),
      m_enemies(m_game->getEnemies()),
      m_isActive(false)
{
  m_textGame.setPosition(m_game->getConfigLoader().get<Rectangle>("DEBUGBAR_TEXT_GAME").getShape().getPosition());
  m_textManager.setPosition(m_game->getConfigLoader().get<Rectangle>("DEBUGBAR_TEXT_MANAGER").getShape().getPosition());
  m_textHero.setPosition(m_game->getConfigLoader().get<Rectangle>("DEBUGBAR_TEXT_HERO").getShape().getPosition());
  m_textMouse.setPosition(m_game->getConfigLoader().get<Rectangle>("DEBUGBAR_TEXT_MOUSE").getShape().getPosition());
  m_textRealFps.setPosition(m_game->getConfigLoader().get<Rectangle>("DEBUGBAR_TEXT_REALFPS").getShape().getPosition());
  m_textRealFps.setFontSize(72);
}

DebugBar::~DebugBar() {}

void DebugBar::update(sf::Time &delta)
{
  m_textGame.addText("fps", "Target FPS: 60");
  m_textGame.addText("fpsvalue", "FPS: " + std::to_string(1.0f / delta.asSeconds()));
  m_textGame.addText("fpsdelta", "Time since last update: " + std::to_string(delta.asSeconds()));
  m_textGame.addText("random", std::to_string(std::rand() % 100000));

  m_textManager.addText("TextureManagerTextures", "TextureManager Textures: " + std::to_string(textureLoader::m_textures.size()));
  m_textManager.addText("FontManagerFonts", "FontManager Fonts: " + std::to_string(fontLoader::m_fonts.size()));

  m_textHero.addText(
      "HeroPosition",
      "Hero x: " + std::to_string(m_hero.getBody().getShape().getPosition().x) + " y: " + std::to_string(m_hero.getBody().getShape().getPosition().y));

  sf::Vector2i mousPos = sf::Mouse::getPosition();
  sf::Vector2f mouseWorldPos = m_window.mapPixelToCoords(mousPos);
  m_textMouse.addText("Mouse", "Mouse: x: " + std::to_string(mousPos.x) + " y: " + std::to_string(mousPos.y));
  m_textMouse.addText("MouseWorld", "Mouse World: x: " + std::to_string(mouseWorldPos.x) + " y: " + std::to_string(mouseWorldPos.y));
}

void DebugBar::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if (m_isActive)
  {
    target.draw(m_debugWindow, states);
    target.draw(m_textGame, states);
    target.draw(m_textManager, states);
    target.draw(m_textHero, states);
    target.draw(m_textMouse, states);
  }
  target.draw(m_textRealFps, states);
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

void DebugBar::setRealFps(float fps)
{
  m_textRealFps.addText("RealFps", "RealFps: " + std::to_string((int)fps));
}
