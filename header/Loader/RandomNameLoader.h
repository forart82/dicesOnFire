#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Helper/RandomHelper.h"

namespace randomNameLoader
{
  inline std::map<int, std::string> m_diceNames;
  inline std::map<int, std::string> m_bladedWeapon;

  inline void load(const std::string &name, const std::string &path)
  {

    std::ifstream file(path);
    if (!file.is_open())
    {
      return;
    }

    std::cout << "load file: " << path << std::endl;

    std::string line;
    while (std::getline(file, line))
    {
      if (line.empty() || line[0] == '#')
        continue;

      std::stringstream ss(line);
      std::string firstToken;
      std::string m_form;
      std::getline(ss, firstToken, ';');

      if (firstToken == "DICENAMES" || firstToken == "BLADEDWEAPONNAMES")
      {
        m_form = firstToken;
        continue;
      }

      if (m_form == "DICENAMES")
      {
        int size = m_diceNames.size() + 1;
        m_diceNames[size] = name;
      }
      else if (m_form == "BLADEDWEAPONNAMES")
      {
        int size = m_bladedWeapon.size() + 1;
        m_bladedWeapon[size] = name;
      }
    }
  }

  inline void loadAll()
  {
    load("Dice", "assets/names/randomDice.names");
    load("Dice", "assets/names/randomWeapon.names");
  }

  inline std::string getRandomDiceName()
  {
    if (m_diceNames.empty())
    {
      loadAll();
    }
    return m_diceNames.at(randomHelper::GET_RANDOM_NUMBER_INT(1, m_diceNames.size()));
  }

  inline std::string getRandomWeaponName()
  {
    if (m_bladedWeapon.empty())
    {
      loadAll();
    }
    return m_bladedWeapon.at(randomHelper::GET_RANDOM_NUMBER_INT(1, m_bladedWeapon.size()));
  }
}