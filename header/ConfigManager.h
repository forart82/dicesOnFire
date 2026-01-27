#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Form/BaseCircle.h"
#include "Form/BaseRectangle.h"
#include "Form/BaseRectangleX2.h"

namespace config
{

  // Data Storage
  inline std::string m_fileName;
  inline std::vector<std::string> m_fileNames;
  inline std::map<std::string, BaseRectangle> m_rectangle;
  inline std::map<std::string, BaseRectangleX2> m_rectangleX2;
  inline std::map<std::string, BaseCircle> m_circle;
  inline std::string m_form = "";

  // Default Values
  inline const BaseRectangle DEFAULT_RECTANGLE = {{0.f, 0.f}, {0.f, 0.f}, 1, true, sf::Color::Red, sf::Color::Black};
  inline const BaseRectangleX2 DEFAULT_RECTANGLEX2 = {DEFAULT_RECTANGLE, DEFAULT_RECTANGLE};
  inline const BaseCircle DEFAULT_CIRCLE = {{0.f, 0.f}, 0.f, 1, true, sf::Color::Red, sf::Color::Black};

  // Getters
  inline BaseRectangle getRectangle(const std::string &key)
  {
    auto it = m_rectangle.find(key);
    return (it != m_rectangle.end()) ? it->second : DEFAULT_RECTANGLE;
  }

  inline BaseRectangleX2 getRectangleX2(const std::string &key)
  {
    auto it = m_rectangleX2.find(key);
    return (it != m_rectangleX2.end()) ? it->second : DEFAULT_RECTANGLEX2;
  }

  inline BaseCircle getCircle(const std::string &key)
  {
    auto it = m_circle.find(key);
    return (it != m_circle.end()) ? it->second : DEFAULT_CIRCLE;
  }

  // Helper to safely parse strings to float/int
  inline float toFloat(const std::string &s) { return s.empty() ? 0.f : std::stof(s); }
  inline std::uint8_t toUnit8(const std::string &s) { return s.empty() ? 0 : static_cast<std::uint8_t>(std::stoi(s)); }
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

  inline BaseRectangle readRectangle(std::stringstream &ss)
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

  inline BaseCircle readCircle(std::stringstream &ss)
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

      std::string line;
      while (std::getline(file, line))
      {
        if (line.empty() || line[0] == '#')
          continue;

        std::stringstream ss(line);
        std::string firstToken;
        std::getline(ss, firstToken, ';');

        if (firstToken == "RECTANGLE" || firstToken == "CIRCLE" || firstToken == "RECTANGLEX2")
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
      }

      file.close();
    }
    return true;
  }

  inline void reload()
  {
    if (!m_fileName.empty())
      load();
  }
}
