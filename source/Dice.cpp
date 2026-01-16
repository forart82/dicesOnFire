#include <SFML/Graphics.hpp>
#include "../header/Dice.h"
#include "../header/Timer.h"
#include "../header/GameText.h"
#include "../header/_GLOBALS.h"

Dice::Dice() : Dice(4, 1, {500.f, 500.f}, {100.f, 100.f}, COLOR_CORAL)
{
}
Dice::Dice(int faces, int rerolles, sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
  this->m_timer = Timer(10);

  this->m_faces = faces;
  this->m_rerolls = rerolles;
  this->m_slot.setPosition(position);
  this->m_slot.setRadius(size.x);
  this->m_slot.setFillColor(color);
}
Dice::~Dice() { ; }

void Dice::update(sf::Time &delta) {}

void Dice::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(this->m_slot);
  target.draw(this->m_faceValueText);
}