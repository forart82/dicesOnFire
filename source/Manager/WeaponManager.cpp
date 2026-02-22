#include "Manager/WeaponManager.h"

WeaponManager::WeaponManager() {}

WeaponManager::~WeaponManager() {}

std::unique_ptr<BladedWeapon> WeaponManager::createBladedWeapon()
{
  auto weapon = std::make_unique<BladedWeapon>();
  weapon->setGame(m_game);

  weapon->setDamage(randomHelper::GET_RANDOM_NUMBER_INT(1, 10));
  weapon->setNumberOfSlots(randomHelper::GET_RANDOM_NUMBER_INT(1, 4));

  return std::move(weapon);
}

std::unique_ptr<BluntWeapon> WeaponManager::createBluntWeapon()
{
  float cooldown = randomHelper::GET_RANDOM_NUMBER_FLOAT(1, 3);
  int damage = randomHelper::GET_RANDOM_NUMBER_INT(1, 10);
  int numberOfSlots = randomHelper::GET_RANDOM_NUMBER_INT(1, 4);
  int assetsLeft = 1376;
  int assetsTop = 1504;

  auto weapon = std::make_unique<BluntWeapon>();
  weapon->setGame(m_game);

  weapon->setBody(std::make_unique<Rectangle>());
  weapon->setCooldown(cooldown);
  weapon->setDamage(damage);
  weapon->setNumberOfSlots(numberOfSlots);
  weapon->setVertexBodyPosition(sf::Vector2f(0.f, 0.f));
  weapon->setVertexAssetBodyPosition(sf::Vector2f(assetsLeft, assetsTop));

  return std::move(weapon);
}