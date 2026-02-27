#pragma once

#include "Manager/BaseManager.h"

class HeroManager : public BaseManager
{
private:
public:
  HeroManager();
  ~HeroManager();

  std::unique_ptr<Hero> createHero();
};
