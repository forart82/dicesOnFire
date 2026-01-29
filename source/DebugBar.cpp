#include <iostream>
#include "DebugBar.h"
#include "Manager/TextureManager.h"
#include "Manager/ConfigManager.h"
#include "Manager/FontManager.h"

DebugBar::DebugBar() : m_isActive(false)
{
  m_debugText.setPosition({100, 100});
  m_debugTextManager.setPosition({100, 300});
}

DebugBar::~DebugBar()
{
}

void DebugBar::update(sf::Time &delta)
{
  m_debugText.addText("fps", "Target FPS: 60");
  m_debugText.addText("fpsvalue", "FPS: " + std::to_string(1.0f / delta.asSeconds()));
  m_debugText.addText("fpsdelta", "Time since last update: " + std::to_string(delta.asSeconds()));
  m_debugText.addText("random", std::to_string(std::rand() % 100000));

  m_debugTextManager.addText("ConfigManagerRectangles", "ConfigManager Rectangles: " + std::to_string(configManager::m_rectangle.size()));
  m_debugTextManager.addText("ConfigManagerRectangleX2s", "ConfigManager RectangleX2s: " + std::to_string(configManager::m_rectangleX2.size()));
  m_debugTextManager.addText("ConfigManagerCircles", "ConfigManager Circles: " + std::to_string(configManager::m_circle.size()));
  m_debugTextManager.addText("TextureManagerTextures", "TextureManager Textures: " + std::to_string(textureManager::m_textures.size()));
  m_debugTextManager.addText("FontManagerFonts", "FontManager Fonts: " + std::to_string(fontManager::m_fonts.size()));
}

void DebugBar::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if (m_isActive)
  {
    target.draw(m_debugWindow, states);
    target.draw(m_debugText, states);
    target.draw(m_debugTextManager, states);
  }
}

void DebugBar::toggleActive()
{
  m_isActive = !m_isActive;
}

GameText DebugBar::getDebugText()
{
  return m_debugText;
}