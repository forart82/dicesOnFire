#include "Manager/BaseManager.h"

template <typename T>
std::unique_ptr<T> BaseManager::create()
{
  static_assert(
      std::is_base_of_v<Gameable, T>,
      "ERROR: The entity you are trying to create MUST inherit from Gameable!");

  auto entity = std::make_unique<T>();
  entity->setGame(m_game);

  return entity;
}