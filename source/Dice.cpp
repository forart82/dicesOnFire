#include <SFML/Graphics.hpp>
#include <iostream>
#include "../header/Dice.h"
#include "../header/Timer.h"
#include "../header/GameText.h"
#include "../header/_GLOBALS.h"
#include "../header/_HELPERS.h"
#include "../header/_BaseCircle.h"

Dice::Dice()
    : Dice(sf::Vector2f(1000, 1000), 50, COLOR_BLUE_CLOUDY_AQUA, COLOR_GREEN_DARK_GREEN, 4, 1, 2)
{
}

Dice::Dice(sf::Vector2f position, float radius, sf::Color fillColor, sf::Color outlineColor, int faces, int rerolls, float cooldown)
    : _BaseCircle(
          position,
          radius,
          fillColor,
          outlineColor,
          true),
      m_timer(
          {position.x, position.y + radius * 2 + 5.f},
          {radius * 2, 20.f},
          COLOR_TIMER_BACKGROUND,
          COLOR_GRAYSCALE_BLACK,
          {position.x, position.y + radius * 2 + 5.f},
          {radius * 2, 20.f},
          COLOR_TIMER_PROGRESSBAR,
          COLOR_GRAYSCALE_BLACK,
          2,
          cooldown,
          true),
      m_faces(faces),
      m_rerolls(rerolls),
      m_padding(8),
      m_stop(false)
{
  // Dice
  makeFaceValues();
  setPosition(m_position);
  setRadius(m_radius);
  setColors(m_fillColor, m_outlineColor);
  setFaces(m_faces);

  // GameText
  m_diceValueText = std::make_unique<GameText>("dice", "1", sf::Vector2f(m_position.x + m_radius / 2, m_position.y + m_radius / 2 - 20.f), COLOR_BLUE_AQUA, "Quantico");
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
    int diceValue = GET_RANDOM_NUMBER_INT(1, m_faces);
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
  _BaseCircle::draw(target, states);
  target.draw(m_timer);
  target.draw(*m_diceValueText);
}

void Dice::makeFaceValues()
{
  for (int i = 0; i < m_faces; i++)
  {
    // For the moment nothing special
    // we will only create a dice with n faces
    // with a incremented number from 1 to n
    m_faceValues[i + 1] = i + 1;
  }
}

void Dice::handelTextPositionBasedOnDiceValue(int diceValue)
{
  if (diceValue < 10)
  {
    auto newPosition = sf::Vector2f(m_position.x + 28.f, m_position.y + 10.f);
    m_diceValueText->setPosition(newPosition);
  }
  else
  {
    auto newPosition = sf::Vector2f(m_position.x + 10.f, m_position.y + 10.f);
    m_diceValueText->setPosition(newPosition);
  }
}

void Dice::toggleStop()
{
  m_stop = !m_stop;
}

void Dice::setFaces(int faces)
{
  m_faces = faces;
  m_shape.setPointCount(m_faces);
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