#pragma once

#include "Ability/Gameable.h"

class BaseEntity : public Gameable
{
public:
  BaseEntity() = default;
  virtual ~BaseEntity() = default;
};