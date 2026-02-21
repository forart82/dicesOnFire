#include "Manager/HeroManager.h"

HeroManager::HeroManager(Game &game)
    : BaseManager(game)
{
}

HeroManager::~HeroManager() {}

std::unique_ptr<Hero> HeroManager::createHero()
{
  auto hero = std::make_unique<Hero>(m_game);
  hero->setBody(std::make_unique<Rectangle>(configLoader::get<Rectangle>("HERO_BODY")));
  hero->setHealthBar(std::make_unique<RectangleX2>(configLoader::get<RectangleX2>("HERO_HEALTHBAR")));
  hero->setWatchRangeCircle(std::make_unique<Circle>(configLoader::get<Circle>("HERO_WATCH_RANGE")));
  hero->setShortRangeCircle(std::make_unique<Circle>(configLoader::get<Circle>("HERO_SHORT_RANGE")));
  hero->setLongRangeCircle(std::make_unique<Circle>(configLoader::get<Circle>("HERO_LONG_RANGE")));
  hero->setPickUpRangeCircle(std::make_unique<Circle>(configLoader::get<Circle>("HERO_PICK_UP_RANGE")));
  hero->setHealth(100);
  hero->setMaxHealth(100);
  hero->setSpeed(1000);
  hero->setWatchRangeRadius(configLoader::get<int>("PLAYER_WATCH_RADIUS"));
  hero->setShortRangeRadius(25);
  hero->setLongRangeRadius(50);
  hero->setPickUpRangeRadius(50);

  return hero;
}
