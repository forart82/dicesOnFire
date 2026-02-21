#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Entity/Circle.h"
#include "Entity/Rectangle.h"
#include "Entity/RectangleX2.h"

namespace configLoader
{

  struct RectangleConfig
  {
    sf::Vector2f position;
    sf::Vector2f size;
    uint8_t thickness;
    bool isActive;
    sf::Color fillColor;
    sf::Color outlineColor;
  };

  struct CircleConfig
  {
    sf::Vector2f position;
    float radius;
    uint8_t thickness;
    bool isActive;
    sf::Color fillColor;
    sf::Color outlineColor;
  };

  struct RectangleX2Config
  {
    RectangleConfig inner;
    RectangleConfig outer;
  };

  // Data Storage
  inline std::map<std::string, std::string> m_fileNames;
  inline std::map<std::string, RectangleConfig> m_rectangles;
  inline std::map<std::string, RectangleX2Config> m_rectangleX2s;
  inline std::map<std::string, CircleConfig> m_circles;
  inline std::map<std::string, int> m_integers;
  inline std::map<std::string, float> m_floats;
  inline std::map<std::string, sf::Vector2f> m_vector2fs;
  inline std::map<std::string, sf::FloatRect> m_floatRects;
  inline std::string m_form = "";

  // Default Values
  inline const RectangleConfig DEFAULT_RECTANGLE = {{0.f, 0.f}, {0.f, 0.f}, 1, true, sf::Color::Red, sf::Color::Black};
  inline const RectangleX2Config DEFAULT_RECTANGLEX2 = {DEFAULT_RECTANGLE, DEFAULT_RECTANGLE};
  inline const CircleConfig DEFAULT_CIRCLE = {{0.f, 0.f}, 0.f, 1, true, sf::Color::Red, sf::Color::Black};
  inline const int DEFAULT_INTEGER = 0;
  inline const float DEFAULT_FLOAT = 0.f;
  inline const sf::Vector2f DEFAULT_VECTOR2F = {0.f, 0.f};
  inline const sf::FloatRect DEFAULT_FLOATRECT = sf::FloatRect({0.f, 0.f}, {0.f, 0.f});

  // Helper to safely parse strings to float/int
  inline float toFloat(const std::string &s) { return s.empty() ? 0.f : std::stof(s); }
  inline std::uint8_t toUnit8(const std::string &s) { return s.empty() ? 0 : static_cast<std::uint8_t>(std::stoi(s)); }
  inline int toInt(const std::string &s) { return s.empty() ? 0 : std::stoi(s); }
  inline bool toBool(const std::string &s)
  {
    if (s.empty())
      return false;

    if (s == "true" || s == "TRUE")
      return true;
    if (s == "false" || s == "FALSE")
      return false;
    try
    {
      return std::stoi(s) != 0;
    }
    catch (...)
    {
      return false; // En cas d'erreur de format
    }
  }

  inline RectangleConfig readRectangle(std::stringstream &ss)
  {
    std::string x, y, width, height, thinkess, isActive, red1, green1, blue1, alpha1, red2, green2, blue2, alpha2;

    std::getline(ss, x, ';');
    std::getline(ss, y, ';');
    std::getline(ss, width, ';');
    std::getline(ss, height, ';');
    std::getline(ss, thinkess, ';');
    std::getline(ss, isActive, ';');
    std::getline(ss, red1, ';');
    std::getline(ss, green1, ';');
    std::getline(ss, blue1, ';');
    std::getline(ss, alpha1, ';');
    std::getline(ss, red2, ';');
    std::getline(ss, green2, ';');
    std::getline(ss, blue2, ';');
    std::getline(ss, alpha2, ';');

    return {{toFloat(x), toFloat(y)},
            {toFloat(width), toFloat(height)},
            toUnit8(thinkess),
            toBool(isActive),
            {toUnit8(red1), toUnit8(green1), toUnit8(blue1), toUnit8(alpha1)},
            {toUnit8(red2), toUnit8(green2), toUnit8(blue2), toUnit8(alpha2)}};
  }

  inline CircleConfig readCircle(std::stringstream &ss)
  {
    std::string x, y, radius, thikness, isActive, red1, green1, blue1, alpha1, red2, green2, blue2, alpha2;

    std::getline(ss, x, ';');
    std::getline(ss, y, ';');
    std::getline(ss, radius, ';');
    std::getline(ss, thikness, ';');
    std::getline(ss, isActive, ';');
    std::getline(ss, red1, ';');
    std::getline(ss, green1, ';');
    std::getline(ss, blue1, ';');
    std::getline(ss, alpha1, ';');
    std::getline(ss, red2, ';');
    std::getline(ss, green2, ';');
    std::getline(ss, blue2, ';');
    std::getline(ss, alpha2, ';');

    return {
        {toFloat(x), toFloat(y)},
        toFloat(radius),
        toUnit8(thikness),
        toBool(isActive),
        {toUnit8(red1), toUnit8(green1), toUnit8(blue1), toUnit8(alpha1)},
        {toUnit8(red2), toUnit8(green2), toUnit8(blue2), toUnit8(alpha2)}};
  }

  inline int readInteger(std::stringstream &ss)
  {
    std::string value;
    std::getline(ss, value, ';');
    return toInt(value);
  }

  inline float readFloat(std::stringstream &ss)
  {
    std::string value;
    std::getline(ss, value, ';');
    return toFloat(value);
  }

  inline sf::Vector2f readVector2f(std::stringstream &ss)
  {
    std::string x, y;
    std::getline(ss, x, ';');
    std::getline(ss, y, ';');
    return {
        toFloat(x),
        toFloat(y)};
  }

  inline sf::FloatRect readFloatRect(std::stringstream &ss)
  {
    std::string x, y, width, height;
    std::getline(ss, x, ';');
    std::getline(ss, y, ';');
    std::getline(ss, width, ';');
    std::getline(ss, height, ';');
    return sf::FloatRect(
        {toFloat(x),
         toFloat(y)},
        {toFloat(width),
         toFloat(height)});
  }

  inline void parseRectangle(std::stringstream &ss, const std::string &key)
  {
    m_rectangles[key] = readRectangle(ss);
  }

  inline void parseRectangleX2(std::stringstream &ss, const std::string &key)
  {
    m_rectangleX2s[key] = {readRectangle(ss), readRectangle(ss)};
  }

  inline void parseCircle(std::stringstream &ss, const std::string &key)
  {
    m_circles[key] = {readCircle(ss)};
  }

  inline void parseInteger(std::stringstream &ss, const std::string &key)
  {
    m_integers[key] = readInteger(ss);
  }

  inline void parseFloat(std::stringstream &ss, const std::string &key)
  {
    m_floats[key] = readFloat(ss);
  }

  inline void parseVector2f(std::stringstream &ss, const std::string &key)
  {
    m_vector2fs[key] = readVector2f(ss);
  }
  inline void parseFloatRect(std::stringstream &ss, const std::string &key)
  {
    m_floatRects[key] = readFloatRect(ss);
  }

  inline bool load(const std::string &fileName, const std::string &path)
  {
    // Check if std::map contains key
    if (m_fileNames.count(fileName) > 0)
    {
      return false;
    }
    m_fileNames.try_emplace(fileName, path);

    std::ifstream file(path);
    if (!file.is_open())
    {
      return false;
    }

    std::cout << "load file: " << path << std::endl;

    std::string line;
    while (std::getline(file, line))
    {
      if (line.empty() || line[0] == '#')
        continue;

      std::stringstream ss(line);
      std::string firstToken;
      std::getline(ss, firstToken, ';');

      if (firstToken == "RECTANGLE" ||
          firstToken == "CIRCLE" ||
          firstToken == "RECTANGLEX2" ||
          firstToken == "INTEGER" ||
          firstToken == "FLOAT" ||
          firstToken == "VECTOR2F" ||
          firstToken == "FLOATRECT")
      {
        m_form = firstToken;
        continue;
      }

      if (m_form == "RECTANGLE")
        parseRectangle(ss, firstToken);
      else if (m_form == "CIRCLE")
        parseCircle(ss, firstToken);
      else if (m_form == "RECTANGLEX2")
        parseRectangleX2(ss, firstToken);
      else if (m_form == "INTEGER")
        parseInteger(ss, firstToken);
      else if (m_form == "FLOAT")
        parseFloat(ss, firstToken);
      else if (m_form == "VECTOR2F")
        parseVector2f(ss, firstToken);
      else if (m_form == "FLOATRECT")
        parseFloatRect(ss, firstToken);
    }

    file.close();
    return true;
  }

  inline void loadAll()
  {
    load("gui", "assets/configs/gui.config");
    load("hero", "assets/configs/hero.config");
    load("enemy", "assets/configs/enemy.config");
    load("debugBar", "assets/configs/debugBar.config");
    load("globals", "assets/configs/globals.config");
  }

  inline void reload()
  {
    m_rectangles.clear();
    m_circles.clear();
    m_rectangleX2s.clear();
    m_integers.clear();
    m_floats.clear();
    m_vector2fs.clear();
    m_floatRects.clear();

    m_fileNames.clear();
    m_form = "";
    loadAll();
  }

  // MARK: GET FUNCTION
  template <typename T>
  inline T get(const std::string &key)
  {
    if constexpr (std::is_same_v<T, int>)
    {
      if (m_integers.empty())
        loadAll();

      auto it = m_integers.find(key);
      return (it != m_integers.end()) ? it->second : DEFAULT_INTEGER;
    }
    else if constexpr (std::is_same_v<T, float>)
    {
      if (m_floats.empty())
        loadAll();

      auto it = m_floats.find(key);
      return (it != m_floats.end()) ? it->second : DEFAULT_FLOAT;
    }
    else if constexpr (std::is_same_v<T, RectangleConfig>)
    {
      if (m_rectangles.empty())
        loadAll();

      auto it = m_rectangles.find(key);
      return (it != m_rectangles.end()) ? it->second : DEFAULT_RECTANGLE;
    }
    else if constexpr (std::is_same_v<T, RectangleX2Config>)
    {
      if (m_rectangleX2s.empty())
        loadAll();

      auto it = m_rectangleX2s.find(key);
      return (it != m_rectangleX2s.end()) ? it->second : DEFAULT_RECTANGLEX2;
    }
    else if constexpr (std::is_same_v<T, CircleConfig>)
    {
      if (m_circles.empty())
        loadAll();

      auto it = m_circles.find(key);
      return (it != m_circles.end()) ? it->second : DEFAULT_CIRCLE;
    }
    else if constexpr (std::is_same_v<T, sf::Vector2f>)
    {
      if (m_vector2fs.empty())
        loadAll();

      auto it = m_vector2fs.find(key);
      return (it != m_vector2fs.end()) ? it->second : DEFAULT_VECTOR2F;
    }
    else if constexpr (std::is_same_v<T, sf::FloatRect>)
    {
      if (m_floatRects.empty())
        loadAll();

      auto it = m_floatRects.find(key);
      return (it != m_floatRects.end()) ? it->second : DEFAULT_FLOATRECT;
    }
    else
    {
      static_assert(
          std::is_same_v<T, int> ||
              std::is_same_v<T, float> ||
              std::is_same_v<T, RectangleConfig> ||
              std::is_same_v<T, RectangleX2Config> ||
              std::is_same_v<T, CircleConfig> ||
              std::is_same_v<T, sf::Vector2f> ||
              std::is_same_v<T, sf::FloatRect>,
          "Type non supporté !");
      return T();
    }
  }
}
