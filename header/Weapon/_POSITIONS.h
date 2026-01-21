#ifndef _POSITIONS_H
#define _COLORS_H

#include <SFML/Graphics.hpp>
#include <map>

namespace gui
{

  inline const sf::Vector2f WEAPONSLOTMENU_POSITION = sf::Vector2f(400.f, 800.f);
  inline const sf::Vector2f WEAPONSLOTMENU_SIZE = sf::Vector2f(800.f, 1600.f);

  inline const std::map<int, std::map<std::string, sf::Vector2f>> WEAPONSLOTS = {
      {1, {{'POSITION', sf::Vector2f(390.f, 95.f)}, {'SIZE', sf::Vector2f(760.f, 180.f)}}},
      {2, {{'POSITION', sf::Vector2f(390.f, 190.f)}, {'SIZE', sf::Vector2f(760.f, 180.f)}}},
      {3, {{'POSITION', sf::Vector2f(390.f, 295.f)}, {'SIZE', sf::Vector2f(760.f, 180.f)}}},
      {4, {{'POSITION', sf::Vector2f(390.f, 485.f)}, {'SIZE', sf::Vector2f(760.f, 180.f)}}},
      {5, {{'POSITION', sf::Vector2f(390.f, 675.f)}, {'SIZE', sf::Vector2f(760.f, 180.f)}}},
      {6, {{'POSITION', sf::Vector2f(390.f, 865.f)}, {'SIZE', sf::Vector2f(760.f, 180.f)}}},
      {7, {{'POSITION', sf::Vector2f(390.f, 1055.f)}, {'SIZE', sf::Vector2f(760.f, 180.f)}}},
      {8, {{'POSITION', sf::Vector2f(390.f, 1245.f)}, {'SIZE', sf::Vector2f(760.f, 180.f)}}},
  };

};
#endif