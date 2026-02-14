#pragma once

#include <SFML/Graphics.hpp>
#include "Entity/Dice.h"
#include "Entity/VertexRectangle.h"
#include "Entity/Weapon.h"
#include "Loader/TextureLoader.h"

class FloorItems : public sf::Drawable, public VertexRectangle
{
private:
  sf::VertexArray m_vertices;
  std::vector<std::unique_ptr<Dice>> m_dices;
  std::vector<std::unique_ptr<Weapon>> m_weapons;
  sf::Texture m_texture;

public:
  FloorItems();
  ~FloorItems();

  void update(sf::Time &delta);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void addDice(std::unique_ptr<Dice> dice);
  void addWeapon(std::unique_ptr<Weapon> weapon);

  std::vector<std::unique_ptr<Dice>> &getDices();
  int getDicesSize() const;

  std::vector<std::unique_ptr<Weapon>> &getWeapons();
  int getWeaponSize() const;
};