#include <SFML/Graphics.hpp>
#include "../header/Dice.h"
#include "../header/Timer.h"
#include "../header/GameText.h"
#include "../header/_GLOBALS.h"
#include <iostream>

Dice::Dice() : Dice(12, 1, 2, {800.f, 200.f}, {50.f, 50.f}, COLOR_CYBER_PURPLE, COLOR_CRIMSON)
{
}
Dice::Dice(int faces, int rerolles, float cooldown, sf::Vector2f position, sf::Vector2f size, sf::Color slotColor, sf::Color solideColor)
    : m_timer(cooldown, true, {position.x, position.y + size.y * 2 + 5.f}, {size.x * 2, 20.f}, 2), m_padding(8)
{
  this->m_faces = faces;
  this->m_rerolls = rerolles;

  // Slot
  this->m_slot.setPosition(position);
  this->m_slot.setRadius(size.x);
  this->m_slot.setFillColor(slotColor);

  // Solide
  this->m_solide.setPosition({position.x + this->m_padding, position.y + this->m_padding});
  this->m_solide.setRadius(size.x - this->m_padding);
  this->m_solide.setPointCount(faces);
  this->m_solide.setFillColor(solideColor);
  this->m_solide.setOutlineColor(COLOR_BLACK);
  this->m_solide.setOutlineThickness(5);

  // GameText
  this->m_faceValueText = std::make_unique<GameText>("title", "1", sf::Vector2f(100.f, 100.f), COLOR_AQUA, "second");
}
Dice::~Dice() {}

void Dice::update(sf::Time &delta)
{
  this->m_timer.update(delta);
  this->m_faceValueText->addText("title", "1");
}

void Dice::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  target.draw(this->m_slot);
  target.draw(this->m_solide);
  target.draw(this->m_timer);
  target.draw(*this->m_faceValueText);
}
