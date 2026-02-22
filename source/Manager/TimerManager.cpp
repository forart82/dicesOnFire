
#include "Manager/TimerManager.h"

TimerManager::TimerManager() {}
TimerManager::~TimerManager() {}

std::unique_ptr<Timer> TimerManager::createTimer()
{
  auto timer = std::make_unique<Timer>();
  timer->setGame(m_game);
  return timer;
}