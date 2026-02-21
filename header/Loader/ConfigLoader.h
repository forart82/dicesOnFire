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
#include "Loader/BaseLoader.h"

class ConfigLoader : public BaseLoader
{

private:
  std::map<std::string, std::string> m_fileNames;
  std::map<std::string, Rectangle> m_rectangles;
  std::map<std::string, RectangleX2> m_rectangleX2s;
  std::map<std::string, Circle> m_circles;
  std::map<std::string, int> m_integers;
  std::map<std::string, float> m_floats;
  std::map<std::string, sf::Vector2f> m_vector2fs;
  std::map<std::string, sf::FloatRect> m_floatRects;
  std::string m_form = "";

public:
  ConfigLoader(Game &game);
  ~ConfigLoader();

  // Helper to safely parse strings to float/int
  float toFloat(const std::string &s) const;
  std::uint8_t toUnit8(const std::string &s) const;
  int toInt(const std::string &s) const;
  bool toBool(const std::string &s) const;

  const Rectangle &readRectangle(std::stringstream &ss) const;
  const Circle &readCircle(std::stringstream &ss) const;

  int readInteger(std::stringstream &ss) const;
  float readFloat(std::stringstream &ss) const;
  const sf::Vector2f &readVector2f(std::stringstream &ss) const;
  const sf::FloatRect &readFloatRect(std::stringstream &ss) const;

  void parseRectangle(std::stringstream &ss, const std::string &key);
  void parseRectangleX2(std::stringstream &ss, const std::string &key);
  void parseCircle(std::stringstream &ss, const std::string &key);
  void parseInteger(std::stringstream &ss, const std::string &key);
  void parseFloat(std::stringstream &ss, const std::string &key);
  void parseVector2f(std::stringstream &ss, const std::string &key);
  void parseFloatRect(std::stringstream &ss, const std::string &key);

  bool load(const std::string &fileName, const std::string &path);
  void loadAll();
  void reload();

  // MARK: GET FUNCTION
  template <typename T>
  const T &get(const std::string &key) const;
};
