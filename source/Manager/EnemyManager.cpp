#include "Manager/EnemyManager.h"

EnemyManager::EnemyManager(Game &game)
    : BaseManager(game),
      m_hero(game.getHero())
{
  m_enemyBody = std::make_unique<Rectangle>(game);
  m_enemyBody->setBody(configLoader::get<Rectangle>("ENEMY_BODY"));

  m_enemyHealthBar = std::make_unique<RectangleX2>(game);
  m_enemyHealthBar->setBodyX2(configLoader::get<RectangleX2>("ENEMY_HEALTHBAR"));

  m_enemyWatchRange = std::make_unique<Circle>(game);
  m_enemyWatchRange->setBody(configLoader::get<Circle>("ENEMY_WATCH_RANGE"));

  m_enemyShortRange = std::make_unique<Circle>(game);
  m_enemyShortRange->setBody(configLoader::get<Circle>("ENEMY_SHORT_RANGE"));

  m_enemyLongRange = std::make_unique<Circle>(game);
  m_enemyLongRange->setBody(configLoader::get<Circle>("ENEMY_LONG_RANGE"));

  m_enemyPickUpUpRange = std::make_unique<Circle>(game);
  m_enemyPickUpUpRange->setBody(configLoader::get<Circle>("ENEMY_PICK_UP_RANGE"));
}

EnemyManager::~EnemyManager() {}

template <typename T>
void EnemyManager::addPosition(const std::unique_ptr<T> &component, const sf::Vector2f &offset)
{
  component->addPosition(offset);
};

std::unique_ptr<Enemy> EnemyManager::createEnemy()
{
  int health = randomHelper::GET_RANDOM_NUMBER_INT(50, 100);
  int maxHealth = health;
  int speed = randomHelper::GET_RANDOM_NUMBER_INT(50, 100);
  int watchRangeRadius = randomHelper::GET_RANDOM_NUMBER_INT(800, 1000);
  int shortRangeRadius = randomHelper::GET_RANDOM_NUMBER_INT(100, 350);
  int longRangeRadius = randomHelper::GET_RANDOM_NUMBER_INT(shortRangeRadius, shortRangeRadius * 2);
  int pickUpRangeRadius = 50;

  int heroMinX = m_hero.getBody().getBody().getPosition().x - 3000;
  int heroMinY = m_hero.getBody().getBody().getPosition().y - 3000;
  int heroMaxX = m_hero.getBody().getBody().getPosition().x + 2000;
  int heroMaxY = m_hero.getBody().getBody().getPosition().y + 2000;
  int randomX = randomHelper::GET_RANDOM_NUMBER_INT(heroMinX, heroMaxX);
  int randomY = randomHelper::GET_RANDOM_NUMBER_INT(heroMinY, heroMaxY);

  auto body = std::make_unique<Rectangle>(m_enemyBody);
  auto healthBar = std::make_unique<RectangleX2>(m_enemyHealthBar);
  auto watchRangeCircle = std::make_unique<Circle>(m_enemyWatchRange);
  auto shortRangeCircle = std::make_unique<Circle>(m_enemyShortRange);
  auto longRangeCircle = std::make_unique<Circle>(m_enemyLongRange);
  auto pickUpRangeCircle = std::make_unique<Circle>(m_enemyPickUpUpRange);

  watchRangeCircle->setRadius(watchRangeRadius);
  shortRangeCircle->setRadius(shortRangeRadius);
  longRangeCircle->setRadius(longRangeRadius);
  pickUpRangeCircle->setRadius(pickUpRangeRadius);

  watchRangeCircle->setOrigin(
      {static_cast<float>(std::round(watchRangeRadius)),
       static_cast<float>(std::round(watchRangeRadius))});
  shortRangeCircle->setOrigin(
      {static_cast<float>(std::round(shortRangeRadius)),
       static_cast<float>(std::round(shortRangeRadius))});
  longRangeCircle->setOrigin(
      {static_cast<float>(std::round(longRangeRadius)),
       static_cast<float>(std::round(longRangeRadius))});
  pickUpRangeCircle->setOrigin(
      {static_cast<float>(std::round(pickUpRangeRadius)),
       static_cast<float>(std::round(pickUpRangeRadius))});

  body->setPosition(m_hero.getBody().getBody().getPosition() + sf::Vector2f(randomX, randomY));
  healthBar->setOuterPosition(m_hero.getHealthBar().getOuter().getBody().getPosition() + sf::Vector2f(randomX, randomY));
  healthBar->setInnerPosition(m_hero.getHealthBar().getInner().getBody().getPosition() + sf::Vector2f(randomX, randomY));
  watchRangeCircle->setPosition(m_hero.getWatchRangeCircle().getBody().getPosition() + sf::Vector2f(randomX, randomY));
  shortRangeCircle->setPosition(m_hero.getShortRangeCircle().getBody().getPosition() + sf::Vector2f(randomX, randomY));
  longRangeCircle->setPosition(m_hero.getPickUpRangeCircle().getBody().getPosition() + sf::Vector2f(randomX, randomY));

  auto enemy = std::make_unique<Enemy>(m_game);

  enemy->setBody(std::move(body));
  enemy->setHealthBar(std::move(healthBar));
  enemy->setWatchRangeCircle(std::move(watchRangeCircle));
  enemy->setShortRangeCircle(std::move(shortRangeCircle));
  enemy->setLongRangeCircle(std::move(longRangeCircle));
  enemy->setPickUpRangeCircle(std::move(pickUpRangeCircle));
  enemy->setHealth(health);
  enemy->setMaxHealth(maxHealth);
  enemy->setSpeed(speed);
  enemy->setWatchRangeRadius(watchRangeRadius);
  enemy->setShortRangeRadius(shortRangeRadius);
  enemy->setLongRangeRadius(longRangeRadius);
  enemy->setPickUpRangeRadius(pickUpRangeRadius);
  enemy->setAssetPosition(sf::Vector2f(
      800 + (configLoader::get<int>("ASSET_TILE_SIZE") * randomHelper::GET_RANDOM_NUMBER_INT(0, 35)),
      2080 + (configLoader::get<int>("ASSET_TILE_SIZE") * randomHelper::GET_RANDOM_NUMBER_INT(0, 1))));

  return enemy;
};