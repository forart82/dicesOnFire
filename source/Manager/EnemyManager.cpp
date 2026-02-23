#include "Manager/EnemyManager.h"

EnemyManager::EnemyManager()
{
  m_enemyBody = std::make_unique<Rectangle>(
      m_game->getConfigLoader().get<Rectangle>("ENEMY_BODY"));

  m_enemyHealthBar = std::make_unique<RectangleX2>(
      m_game->getConfigLoader().get<RectangleX2>("ENEMY_HEALTHBAR"));

  m_enemyWatchRange = std::make_unique<Circle>(
      m_game->getConfigLoader().get<Circle>("ENEMY_WATCH_RANGE"));

  m_enemyShortRange = std::make_unique<Circle>(
      m_game->getConfigLoader().get<Circle>("ENEMY_SHORT_RANGE"));

  m_enemyLongRange = std::make_unique<Circle>(
      m_game->getConfigLoader().get<Circle>("ENEMY_LONG_RANGE"));

  m_enemyPickUpUpRange = std::make_unique<Circle>(
      m_game->getConfigLoader().get<Circle>("ENEMY_PICK_UP_RANGE"));
}

EnemyManager::~EnemyManager() {}

template <typename T>
void EnemyManager::addPosition(const std::unique_ptr<T> &component, const sf::Vector2f &offset)
{
  component->addPosition(offset);
};

std::unique_ptr<Enemy> EnemyManager::createEnemy()
{
  auto &hero = m_game->getHero();

  int health = randomHelper::GET_RANDOM_NUMBER_INT(50, 100);
  int maxHealth = health;
  int speed = randomHelper::GET_RANDOM_NUMBER_INT(50, 100);
  int watchRangeRadius = randomHelper::GET_RANDOM_NUMBER_INT(800, 1000);
  int shortRangeRadius = randomHelper::GET_RANDOM_NUMBER_INT(100, 350);
  int longRangeRadius = randomHelper::GET_RANDOM_NUMBER_INT(shortRangeRadius, shortRangeRadius * 2);
  int pickUpRangeRadius = 50;

  int heroMinX = hero.getBody().getShape().getPosition().x - 3000;
  int heroMinY = hero.getBody().getShape().getPosition().y - 3000;
  int heroMaxX = hero.getBody().getShape().getPosition().x + 2000;
  int heroMaxY = hero.getBody().getShape().getPosition().y + 2000;
  int randomX = randomHelper::GET_RANDOM_NUMBER_INT(heroMinX, heroMaxX);
  int randomY = randomHelper::GET_RANDOM_NUMBER_INT(heroMinY, heroMaxY);

  auto body = std::make_unique<Rectangle>(*m_enemyBody);
  auto healthBar = std::make_unique<RectangleX2>(*m_enemyHealthBar);
  auto watchRangeCircle = std::make_unique<Circle>(*m_enemyWatchRange);
  auto shortRangeCircle = std::make_unique<Circle>(*m_enemyShortRange);
  auto longRangeCircle = std::make_unique<Circle>(*m_enemyLongRange);
  auto pickUpRangeCircle = std::make_unique<Circle>(*m_enemyPickUpUpRange);

  watchRangeCircle->setRadius(watchRangeRadius);
  shortRangeCircle->setRadius(shortRangeRadius);
  longRangeCircle->setRadius(longRangeRadius);
  pickUpRangeCircle->setRadius(pickUpRangeRadius);

  body->setPosition(hero.getBody().getShape().getPosition() + sf::Vector2f(randomX, randomY));
  healthBar->setOuterPosition(hero.getHealthBar().getOuter().getShape().getPosition() + sf::Vector2f(randomX, randomY));
  healthBar->setInnerPosition(hero.getHealthBar().getInner().getShape().getPosition() + sf::Vector2f(randomX, randomY));
  shortRangeCircle->setPosition(hero.getShortRangeCircle().getShape().getPosition() + sf::Vector2f(randomX, randomY));
  longRangeCircle->setPosition(hero.getPickUpRangeCircle().getShape().getPosition() + sf::Vector2f(randomX, randomY));

  auto enemy = std::make_unique<Enemy>();
  enemy->setGame(m_game);

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
  enemy->setVertexAssetBodyPosition(sf::Vector2f(
      800 + (m_game->getConfigLoader().get<int>("ASSET_TILE_SIZE") * randomHelper::GET_RANDOM_NUMBER_INT(0, 35)),
      2080 + (m_game->getConfigLoader().get<int>("ASSET_TILE_SIZE") * randomHelper::GET_RANDOM_NUMBER_INT(0, 1))));

  return enemy;
};