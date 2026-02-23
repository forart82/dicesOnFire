#pragma once

#include "Ability/Gameable.h"

class BaseManager : public Gameable
{
public:
  BaseManager() = default;
  virtual ~BaseManager() = default;

  template <typename T>
  std::unique_ptr<T> create();
};