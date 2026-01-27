#include <SFML/Graphics.hpp>
#include "Entity/BaseEntity.h"
#include "Entity/Hero.h"
#include "Form/BaseRectangle.h"
#include "Form/BaseRectangleX2.h"

Hero::Hero()
    : Hero(std::make_unique<BaseRectangle>(),
           std::make_unique<BaseRectangleX2>(),
           100,
           100,
           2)
{
}

Hero::Hero(
    std::unique_ptr<BaseRectangle> body,
    std::unique_ptr<BaseRectangleX2> healthBar,
    float health,
    float maxHealth,
    float speed)
    : BaseEntity(
          std::move(body),
          std::move(healthBar),
          health,
          maxHealth,
          speed)
{
}

Hero::~Hero() {}