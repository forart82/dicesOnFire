#include <SFML/Graphics.hpp>
#include "../header/Dice.h"
#include "../header/Timer.h"
#include "../header/GameText.h"
#include "../header/_GLOBALS.h"
#include <iostream>

Dice::Dice() : Dice(99, 1, 2, {800.f, 200.f}, {50.f, 50.f}, COLOR_CYBER_PURPLE, COLOR_CRIMSON)
{
}
Dice::Dice(int faces, int rerolles, float cooldown, sf::Vector2f position, sf::Vector2f size, sf::Color slotColor, sf::Color solideColor)
    : m_timer(cooldown, true, {position.x, position.y + size.y * 2 + 5.f}, {size.x * 2, 20.f}, 2), m_padding(8), m_stop(false)
{
  // Dice
  m_faces = faces;
  m_rerolls = rerolles;
  makeFaceValues();

  // Slot
  m_slot.setPosition(position);
  m_slot.setRadius(size.x);
  m_slot.setFillColor(slotColor);

  // Solide
  m_solide.setPosition({position.x + m_padding, position.y + m_padding});
  m_solide.setRadius(size.x - m_padding);
  m_solide.setPointCount(faces);
  m_solide.setFillColor(solideColor);
  m_solide.setOutlineColor(COLOR_BLACK);
  m_solide.setOutlineThickness(5);

  // GameText
  m_diceValueText = std::make_unique<GameText>("dice", "1", sf::Vector2f(position.x + size.x / 2, position.y + size.y / 2 - 20.f), COLOR_AQUA, "Quantico");
  m_diceValueText->setFontSize(63);

  // Timer
  m_timer.onTimeout = [this]()
  { onTimeout(); };
}
Dice::~Dice() {}

void Dice::update(sf::Time &delta)
{
  if (!m_stop)
  {
    m_timer.update(delta);
    auto diceValue = (int)roll();
    m_diceValueText->addText("dice", std::to_string(diceValue));
    handelTextPositionBasedOnDiceValue(diceValue);
  }
  if (m_stop)
  {
    m_elapsedTime += delta;
    if (m_elapsedTime.asSeconds() >= 0.5f)
    {
      m_timer.toggleStop();
      toggleStop();
      m_elapsedTime = sf::Time::Zero;
    }
  }
}

void Dice::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  target.draw(m_slot);
  target.draw(m_solide);
  target.draw(m_timer);
  target.draw(*m_diceValueText);
}

void Dice::makeFaceValues()
{
  for (int i = 0; i < m_faces; i++)
  {
    // for the moment nothing special
    // we will only create a dice with n faces
    // with a incremented number from 1 to n
    m_faceValues[i + 1] = i + 1;
  }
}

void Dice::handelTextPositionBasedOnDiceValue(int diceValue)
{
  auto position = m_slot.getPosition();
  auto radius = m_slot.getRadius();
  if (diceValue < 10)
  {
    auto newPosition = sf::Vector2f(position.x + 28.f, position.y + 10.f);
    m_diceValueText->setPosition(newPosition);
  }
  else
  {
    auto newPosition = sf::Vector2f(position.x + 10.f, position.y + 10.f);
    m_diceValueText->setPosition(newPosition);
  }
}

void Dice::toggleStop()
{
  m_stop = !m_stop;
}

void Dice::onTimeout()
{
  m_timer.toggleStop();
  toggleStop();
}

float Dice::roll()
{
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(1, m_faces);
  int result = dist(gen);
  return m_faceValues[result];
}
