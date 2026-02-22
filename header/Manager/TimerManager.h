#pragma once

#include "Manager/BaseManager.h"
#include "Entity/Timer.h"

class TimerManager : public BaseManager
{

public:
  TimerManager();
  ~TimerManager();
  std::unique_ptr<Timer> createTimer();
};