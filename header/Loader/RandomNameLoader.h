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
  inline std ::map<std::string, std::string> m_fileNames;
  inline std::map<int, std::string> m_dices;
  inline std::map<int, std::string> m_bladedWeapons;
  inline std::string DEFAULT_NAME = "Some Name";

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
    std::string m_form;
    while (std::getline(file, line))
    {
      if (line.empty() || line[0] == '#')
        continue;

      std::stringstream ss(line);
      std::string firstToken;
      std::getline(ss, firstToken, ';');

      if (firstToken == "DICENAMES" || firstToken == "BLADEDWEAPONNAMES")
      {
        m_form = firstToken;
        continue;
      }

      if (m_form == "DICENAMES")
      {
        int size = m_dices.size() + 1;
        m_dices[size] = firstToken;
      }
      else if (m_form == "BLADEDWEAPONNAMES")
      {
        int size = m_bladedWeapons.size() + 1;
        m_bladedWeapons[size] = firstToken;
      }
    }
    return true;
  }

  inline void loadAll()
  {
    load("randomDice", "assets/names/randomDice.names");
    load("randomWeapons", "assets/names/randomWeapons.names");
  }

  inline void reload()
  {
    m_fileNames.clear();
    m_dices.clear();
    m_bladedWeapons.clear();
    loadAll();
  }

  inline std::string getRandomDiceName()
  {
    if (m_dices.empty())
    {
      loadAll();
    }
    if (m_dices.size() == 0)
      return DEFAULT_NAME;
    return m_dices.at(randomHelper::GET_RANDOM_NUMBER_INT(1, m_dices.size()));
  }

  inline std::string getRandomWeaponName()
  {
    if (m_bladedWeapons.empty())
    {
      loadAll();
    }

    if (m_bladedWeapons.size() == 0)
      return DEFAULT_NAME;
    return m_bladedWeapons.at(randomHelper::GET_RANDOM_NUMBER_INT(1, m_bladedWeapons.size()));
  }
}