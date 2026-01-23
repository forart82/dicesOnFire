#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

namespace config
{

  struct Rectangle
  {
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color innerColor;
    sf::Color outerColor;
    int thickness;
  };

  struct Circle 
  {
    sf:: Vector2F position;
    float radius;
    sf::Color innerColor;
    sf::Color outerColor;
    int thickness;
  }
  
  inline std::string m_fileName;

  inline std::map<std::string, Rectangle> m_rectangle;
  inline std::map<std::string, Circle> m_circle;
 
  inline std:: m_form = "";

  inline const Rectangle DEFAULT_RECTANGLE = {
      {0.f, 0.f},
      {0.f, 0.f},
      sf::Color::Red,
      sf::Color::Black,
      2
  }
  inline const Circle DEFAULT_CIRCLE = {
      {0.f, 0.f},
      0,
      sf::Color::Red,
      sf::Color::Black,
      2
  }

  inline Rectangle getRectangle(std::string key)
  {
    auto it = m_rectangle.find(key);
    if (it != m_rectangle.end())
    {
      return it->second;
    }
    return DEFAULT_RECTANGLE;
  }

  inline Circle getCircle(std::string key)
  {
    auto it = m_circle.find(key);
    if (it != m_circle.end())
    {
      return it->second;
    }
    return DEFAULT_CIRCLE;
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
      std::string key = std::getline(ss, key, ';');

      if(m_form=="RECTANGLE"){
        makeRectangle(key, ss);
      }

      m_form=key;
    }

    file.close();
    return true;
  }

  inline makeRectangle(
    std::string key, 
    std::stringstream ss)
  {
      std::string 
        x_str, 
        y_str, 
        width_str,
        height_str,
        r1_str, 
        g1_str, 
        b1_str, 
        a1_str,
        r2_str, 
        g2_str, 
        b2_str, 
        a2_str,
        thickness_str;
       
      std::getline(ss, x_str, ';');
      std::getline(ss, y_str, ';');
      std::getline(ss, width_str, ';');
      std::getline(ss, height_str, ';');
      std::getline(ss, r1_str, ';');
      std::getline(ss, g1_str, ';');
      std::getline(ss, b1_str, ';');
      std::getline(ss, a1_str, ';');
      std::getline(ss, r2_str, ';');
      std::getline(ss, g2_str, ';');
      std::getline(ss, b2_str, ';');
      std::getline(ss, a2_str, ';');
      std::getline(ss, thickness_str, ';');
 

      if ( 
         !key.empty() && 
         !x_str.empty() && 
         !y_str.empty() &&
         !widthv_str.empty() &&
         !r_str.empty() && 
         !g_str.empty() && 
         !b_str.empty() && 
         !a_str.empty() &&
         !r_str.empty() &&
         !r_str.empty() &&
         !r_str.empty() &&
         !r_str.empty() &&
         !r_str.empty())
      {
        float x = std::stof(x_str);
        float y = std::stof(y_str);
        float width = std::stof(width_str);
        float height std::stof(height_dtr);
        int r = std::stof(r_str);
        int g = std::stof(g_str);
        int b = std::stof(b_str);
        int a = std::stof(a_str);
        m_rectangle[key] = {
          sf::Vector2f(x, y),
          sf::Vector2f(width, height),
          

  }

  inline void reload()
  {
    load(m_fileName);
  }
};