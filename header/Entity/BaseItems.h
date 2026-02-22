#pragma once

#include "Ability/VertexRectangleDrawable.h"
#include "Entity/BaseEntity.h"
#include "Entity/Dice.h"
#include "Entity/BaseWeapon.h"
#include "Loader/TextureLoader.h"

class BaseItems : public BaseEntity, public sf::Drawable
{
protected:
  std::vector<std::unique_ptr<Dice>> m_dices;
  std::vector<std::unique_ptr<BaseWeapon>> m_weapons;

public:
  BaseItems() = default;
  virtual ~BaseItems() = default;

  virtual void update(sf::Time &delta) = 0;
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override = 0;

  virtual void addDice(std::unique_ptr<Dice> dice);
  virtual void addWeapon(std::unique_ptr<BaseWeapon> weapon);

  virtual const std::vector<std::unique_ptr<Dice>> &getDices() const;
  virtual int getDicesSize() const;

  virtual const std::vector<std::unique_ptr<BaseWeapon>> &getWeapons() const;
  virtual int getWeaponSize() const;
};