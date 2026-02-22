#pragma once

#include "Loader/BaseLoader.h"
#include "Helper/RandomHelper.h"

class RandomNameLoader : public BaseLoader
{
private:
  std ::map<std::string, std::string> m_fileNames;
  std::map<int, std::string> m_dices;
  std::map<int, std::string> m_bladedWeapons;
  std::string m_defaultName;

public:
  RandomNameLoader();
  ~RandomNameLoader();

  bool load(const std::string &fileName, const std::string &path);
  void loadAll();
  void reload();
  const std::string &getRandomDiceName();
  const std::string &getRandomWeaponName();
};