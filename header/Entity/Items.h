#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/VertexRectangle.h"
#include "Entity/Dice.h"
#include "Entity/Weapon.h"
#include "Loader/TextureLoader.h"

class Items : public sf::Drawable
{
protected:
  sf::VertexArray m_vertices;
  std::vector<std::unique_ptr<Dice>> m_dices;
  std::vector<std::unique_ptr<Weapon>> m_weapons;
  const sf::Texture *m_texture;

public:
  Items() = default;
  virtual ~Items() = default;

  virtual void update(sf::Time &delta) = 0;
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override = 0;

  virtual void addDice(std::unique_ptr<Dice> dice);
  virtual void addWeapon(std::unique_ptr<Weapon> weapon);

  virtual std::vector<std::unique_ptr<Dice>> &getDices();
  virtual int getDicesSize() const;

  virtual std::vector<std::unique_ptr<Weapon>> &getWeapons();
  virtual int getWeaponSize() const;
};