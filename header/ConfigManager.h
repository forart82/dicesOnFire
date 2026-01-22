#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

namespace config
{

  struct GUI_ELEMENT
  {
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color color;
  };

  inline std::map<std::string, GUI_ELEMENT> m_gui;
  inline std::string m_fileName;
  inline const GUI_ELEMENT DEFAULT_BUTTON = {
      {0.f, 0.f},
      {0.f, 0.f},
      sf::Color::Red};

  inline GUI_ELEMENT getKey(std::string key)
  {
    auto it = m_gui.find(key);
    if (it != m_gui.end())
    {
      return it->second;
    }
    return DEFAULT_BUTTON;
  }

  inline bool load(std::string fileName)
  {
    m_fileName = fileName;
    std::ifstream file(fileName);
    if (!file.is_open())
    {
      std::cerr << "Erreur : Impossible d'ouvrir " << fileName << std::endl;
      return false;
    }

    std::string line;
    while (std::getline(file, line))
    {
      std::stringstream ss(line);
      std::string key, x_str, y_str, r_str, g_str, b_str, a_str;
      std::getline(ss, key, ';');
      std::getline(ss, x_str, ';');
      std::getline(ss, y_str, ';');
      std::getline(ss, r_str, ';');
      std::getline(ss, g_str, ';');
      std::getline(ss, b_str, ';');
      std::getline(ss, a_str);

      if (!key.empty() && !x_str.empty() && !y_str.empty() && !r_str.empty() && !g_str.empty() && !b_str.empty() && !a_str.empty())
      {
        float x = std::stof(x_str);
        float y = std::stof(y_str);
        int r = std::stof(r_str);
        int g = std::stof(g_str);
        int b = std::stof(b_str);
        int a = std::stof(a_str);
        m_gui[key] = {
          sf::Vector2f(x, y);
      }
      std::cout << key << " " << x << " " << y << std::endl;
    }
  }

  file.close();
  return true;
}

inline void reload()
{
  load(m_fileName);
}
}
;