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

  // Data Storage
  inline std::vector<std::string> m_fileNames;
  inline std::map<std::string, Rectangle> m_rectangle;
  inline std::map<std::string, RectangleX2> m_rectangleX2;
  inline std::map<std::string, Circle> m_circle;
  inline std::map<std::string, int> m_globalInteger;
  inline std::map<std::string, float> m_globalFloat;
  inline std::string m_form = "";

  // Default Values
  inline const Rectangle DEFAULT_RECTANGLE = {{0.f, 0.f}, {0.f, 0.f}, 1, true, sf::Color::Red, sf::Color::Black};
  inline const RectangleX2 DEFAULT_RECTANGLEX2 = {DEFAULT_RECTANGLE, DEFAULT_RECTANGLE};
  inline const Circle DEFAULT_CIRCLE = {{0.f, 0.f}, 0.f, 1, true, sf::Color::Red, sf::Color::Black};
  inline const int DEFAULT_INTEGER = 0;
  inline const float DEFAULT_FLOAT = 0.f;

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

  inline Rectangle readRectangle(std::stringstream &ss)
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

  inline Circle readCircle(std::stringstream &ss)
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

  inline void parseRectangle(std::stringstream &ss, const std::string &key)
  {
    m_rectangle[key] = readRectangle(ss);
  }

  inline void parseRectangleX2(std::stringstream &ss, const std::string &key)
  {
    m_rectangleX2[key] = {readRectangle(ss), readRectangle(ss)};
  }

  inline void parseCircle(std::stringstream &ss, const std::string &key)
  {
    m_circle[key] = {readCircle(ss)};
  }

  inline void parseInteger(std::stringstream &ss, const std::string &key)
  {
    m_globalInteger[key] = readInteger(ss);
  }

  inline void parseFloat(std::stringstream &ss, const std::string &key)
  {
    m_globalFloat[key] = readFloat(ss);
  }

  inline bool load(const std::string &fileName = "")
  {
    if (fileName.length() > 0)
    {
      m_fileNames.push_back(fileName);
    }

    m_rectangle.clear();
    m_rectangleX2.clear();
    m_circle.clear();
    m_form = "";

    for (const auto &listedFileName : m_fileNames)
    {
      std::ifstream file(listedFileName);
      if (!file.is_open())
      {
        continue;
      }

      std::cout << "load file: " << listedFileName << std::endl;

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
            firstToken == "FLOAT")
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
      }

      file.close();
    }
    std::cout << " load end " << m_rectangle.size() << " " << m_fileNames.size() << std::endl;

    return true;
  }

  inline void loadAll()
  {
    m_fileNames.clear();
    load("assets/configs/gui.config");
    load("assets/configs/hero.config");
    load("assets/configs/enemy.config");
    load("assets/configs/debugBar.config");
    load("assets/configs/globals.config");
  }

  inline void reload()
  {
    m_rectangle.clear();
    m_circle.clear();
    m_rectangleX2.clear();
    m_globalInteger.clear();
    m_globalFloat.clear();
    load();
  }

  // Getters
  inline Rectangle getRectangle(const std::string &key)
  {
    if (m_rectangle.empty())
    {
      loadAll();
    }
    auto it = m_rectangle.find(key);
    return (it != m_rectangle.end()) ? it->second : DEFAULT_RECTANGLE;
  }

  inline RectangleX2 getRectangleX2(const std::string &key)
  {
    if (m_rectangleX2.empty())
    {
      loadAll();
    }
    auto it = m_rectangleX2.find(key);
    return (it != m_rectangleX2.end()) ? it->second : DEFAULT_RECTANGLEX2;
  }

  inline Circle getCircle(const std::string &key)
  {
    if (m_circle.empty())
    {
      loadAll();
    }
    auto it = m_circle.find(key);
    return (it != m_circle.end()) ? it->second : DEFAULT_CIRCLE;
  }

  inline int getInteger(const std::string &key)
  {
    if (m_globalInteger.empty())
    {
      loadAll();
    }
    auto it = m_globalInteger.find(key);
    return (it != m_globalInteger.end()) ? it->second : DEFAULT_INTEGER;
  }

  inline int getFLoat(const std::string &key)
  {
    if (m_globalFloat.empty())
    {
      loadAll();
    }
    auto it = m_globalFloat.find(key);
    return (it != m_globalFloat.end()) ? it->second : DEFAULT_FLOAT;
  }
}
