#include <SFML/Graphics.hpp>
#include "../header/Dice.h"
#include "../header/Timer.h"
#include "../header/GameText.h"
#include "../header/_GLOBALS.h"
#include <iostream>

Dice::Dice() : Dice(6, 1, 2, {450.f, 950.f}, {50.f, 50.f}, COLOR_VIOLET_CYBER_PURPLE, COLOR_RED_CRIMSON)
{
}
Dice::Dice(int faces, int rerolles, float cooldown, sf::Vector2f position, sf::Vector2f size, sf::Color slotColor, sf::Color solideColor)
    : m_timer(
          cooldown,
          true,
          {position.x, position.y + size.y * 2 + 5.f},
          {size.x * 2, 20.f}, 2),
      m_faces(m_faces),
      m_rerolls(rerolles),
      m_padding(8),
      m_stop(false)
{
  // Dice
  makeFaceValues();
  setPosition(position);
  setSize(size);
  m_slotShape.setFillColor(slotColor);
  setSolideColor(solideColor, COLOR_GRAYSCALE_BLACK);
  setFaces(faces);

  // GameText
  m_diceValueText = std::make_unique<GameText>("dice", "1", sf::Vector2f(position.x + size.x / 2, position.y + size.y / 2 - 20.f), COLOR_BLUE_AQUA, "Quantico");
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
  target.draw(m_slotShape);
  target.draw(m_solideShape);
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
  auto position = m_slotShape.getPosition();
  auto radius = m_slotShape.getRadius();
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

void Dice::setPosition(sf::Vector2f position)
{
  m_slotShape.setPosition(position);
  m_solideShape.setPosition({position.x + m_padding, position.y + m_padding});
}
void Dice::setSize(sf::Vector2f size)
{
  m_slotShape.setRadius(size.x);
  m_solideShape.setRadius(size.x - m_padding);
}
void Dice::setSolideColor(sf::Color solideColor, sf::Color outlineColor)
{
  m_solideShape.setFillColor(solideColor);
  m_solideShape.setOutlineColor(outlineColor);
  m_solideShape.setOutlineThickness(5);
}
void Dice::setFaces(int faces)
{
  m_faces = faces;
  makeFaceValues();
}
void Dice::setRerolls(int rerolls)
{
  m_rerolls = rerolls;
}
void Dice::setCooldown(float cooldown)
{
  m_timer.setCooldown(cooldown);
}
void Dice::setFaceValues(std::map<int, float> faceValues)
{
  if (faceValues.size() == m_faces)
  {
    m_faceValues = faceValues;
  }
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
