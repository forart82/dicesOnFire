#include "Manager/HeroManager.h"

HeroManager::HeroManager() {}

HeroManager::~HeroManager() {}

std::unique_ptr<Hero> HeroManager::createHero()
{
  auto hero = std::make_unique<Hero>();
  hero->setGame(m_game);

  hero->setBody(std::make_unique<Rectangle>(m_game->getConfigLoader().get<Rectangle>("HERO_BODY")));
  hero->setHealthBar(std::make_unique<RectangleX2>(m_game->getConfigLoader().get<RectangleX2>("HERO_HEALTHBAR")));
  hero->setWatchRangeCircle(std::make_unique<Circle>(m_game->getConfigLoader().get<Circle>("HERO_WATCH_RANGE")));
  hero->setShortRangeCircle(std::make_unique<Circle>(m_game->getConfigLoader().get<Circle>("HERO_SHORT_RANGE")));
  hero->setLongRangeCircle(std::make_unique<Circle>(m_game->getConfigLoader().get<Circle>("HERO_LONG_RANGE")));
  hero->setPickUpRangeCircle(std::make_unique<Circle>(m_game->getConfigLoader().get<Circle>("HERO_PICK_UP_RANGE")));
  hero->setHealth(100);
  hero->setMaxHealth(100);
  hero->setMovementSpeed(1000);
  hero->setWatchRangeRadius(m_game->getConfigLoader().get<int>("PLAYER_WATCH_RADIUS"));
  hero->setShortRangeRadius(25);
  hero->setLongRangeRadius(50);
  hero->setPickUpRangeRadius(50);

  return hero;
}
