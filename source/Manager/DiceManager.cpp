#include "Manager/DiceManager.h"

DiceManager::DiceManager(Game &game)
    : BaseManager(game) {}

DiceManager::~DiceManager() {}

std::unique_ptr<Dice> DiceManager::createDice(int level = 1)
{
  auto dice = std::make_unique<Dice>();

  int assetLeft = 960 + (configLoader::get<int>("ASSET_TILE_SIZE") * randomHelper::GET_RANDOM_NUMBER_INT(0, 5));
  int assetTop = 1312;

  switch (level)
  {
  case 1:
    dice->setCooldown(randomHelper::GET_RANDOM_NUMBER_FLOAT(1, 5));
    dice->setFaces(4);
    dice->setIsOnFloor(false);
    dice->setRerolls(0);
    dice->setAssetPosition(sf::Vector2f(assetLeft, assetTop));
    break;
  }

  return dice;
}