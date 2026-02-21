#include "Loader/ConfigLoader.h"

ConfigLoader::ConfigLoader(Game &game)
    : BaseLoader(game) {}

ConfigLoader::~ConfigLoader() {}

// Helper to safely parse strings to float/int
float ConfigLoader::toFloat(const std::string &s) const
{
  return s.empty() ? 0.f : std::stof(s);
}

std::uint8_t ConfigLoader::toUnit8(const std::string &s) const
{
  return s.empty() ? 0 : static_cast<std::uint8_t>(std::stoi(s));
}

int ConfigLoader::toInt(const std::string &s) const
{
  return s.empty() ? 0 : std::stoi(s);
}

bool ConfigLoader::toBool(const std::string &s) const
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

const Rectangle &ConfigLoader::readRectangle(std::stringstream &ss) const
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

const Circle &ConfigLoader::readCircle(std::stringstream &ss) const
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

int ConfigLoader::readInteger(std::stringstream &ss) const
{
  std::string value;
  std::getline(ss, value, ';');
  return toInt(value);
}

float ConfigLoader::readFloat(std::stringstream &ss) const
{
  std::string value;
  std::getline(ss, value, ';');
  return toFloat(value);
}

const sf::Vector2f &ConfigLoader::readVector2f(std::stringstream &ss) const
{
  std::string x, y;
  std::getline(ss, x, ';');
  std::getline(ss, y, ';');
  return {
      toFloat(x),
      toFloat(y)};
}

const sf::FloatRect &ConfigLoader::readFloatRect(std::stringstream &ss) const
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

void ConfigLoader::parseRectangle(std::stringstream &ss, const std::string &key)
{
  m_rectangles[key] = readRectangle(ss);
}

void ConfigLoader::parseRectangleX2(std::stringstream &ss, const std::string &key)
{
  m_rectangleX2s[key] = {readRectangle(ss), readRectangle(ss)};
}

void ConfigLoader::parseCircle(std::stringstream &ss, const std::string &key)
{
  m_circles[key] = {readCircle(ss)};
}

void ConfigLoader::parseInteger(std::stringstream &ss, const std::string &key)
{
  m_integers[key] = readInteger(ss);
}

void ConfigLoader::parseFloat(std::stringstream &ss, const std::string &key)
{
  m_floats[key] = readFloat(ss);
}

void ConfigLoader::parseVector2f(std::stringstream &ss, const std::string &key)
{
  m_vector2fs[key] = readVector2f(ss);
}
void ConfigLoader::parseFloatRect(std::stringstream &ss, const std::string &key)
{
  m_floatRects[key] = readFloatRect(ss);
}

bool ConfigLoader::load(const std::string &fileName, const std::string &path)
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

void ConfigLoader::loadAll()
{
  load("gui", "assets/configs/gui.config");
  load("hero", "assets/configs/hero.config");
  load("enemy", "assets/configs/enemy.config");
  load("debugBar", "assets/configs/debugBar.config");
  load("globals", "assets/configs/globals.config");
}

void ConfigLoader::reload()
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
T ConfigLoader::get(const std::string &key)
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
  else if constexpr (std::is_same_v<T, Rectangle>)
  {
    if (m_rectangles.empty())
      loadAll();

    auto it = m_rectangles.find(key);
    return (it != m_rectangles.end()) ? it->second : DEFAULT_RECTANGLE;
  }
  else if constexpr (std::is_same_v<T, RectangleX2>)
  {
    if (m_rectangleX2s.empty())
      loadAll();

    auto it = m_rectangleX2s.find(key);
    return (it != m_rectangleX2s.end()) ? it->second : DEFAULT_RECTANGLEX2;
  }
  else if constexpr (std::is_same_v<T, Circle>)
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
            std::is_same_v<T, Rectangle> ||
            std::is_same_v<T, RectangleX2> ||
            std::is_same_v<T, Circle> ||
            std::is_same_v<T, sf::Vector2f> ||
            std::is_same_v<T, sf::FloatRect>,
        "Type non supporté !");
    return T();
  }
}
