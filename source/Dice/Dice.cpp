#include "Dice/Dice.h"

Dice::Dice()
    : Dice(
          BaseCircle(
              sf::Vector2f(1000, 1000),
              50,
              1, true,
              colors::COLOR_BLUE_CLOUDY_AQUA,
              colors::COLOR_GREEN_DARK_GREEN),
          4,
          1,
          2)
{
}

Dice::Dice(BaseCircle diceMenu, int faces, int rerolls, float cooldown)
    : m_diceMenu(diceMenu),
      m_timer(10),
      m_faces(faces),
      m_rerolls(rerolls),
      m_padding(8),
      m_stop(false)
{
  // Dice
  makeFaceValues();
  // m_shape.setPosition(position);
  // m_shape.setRadius(m_radius);
  // setColors(m_fillColor, m_outlineColor);
  // setFaces(m_faces);

  // GameText
  // m_diceValueText = std::make_unique<GameText>("dice", "1", sf::Vector2f(m_position.x + m_radius / 2, m_position.y + m_radius / 2 - 20.f), colors::COLOR_BLUE_AQUA, "Quantico");
  // m_diceValueText->setFontSize(63);

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
    int diceValue = helper::GET_RANDOM_NUMBER_INT(1, m_faces);
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
  BaseCircle::draw(target, states);
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
    // auto newPosition = sf::Vector2f(m_position.x + 28.f, m_position.y + 10.f);
    // m_diceValueText->setPosition(newPosition);
  }
  else
  {
    // auto newPosition = sf::Vector2f(m_position.x + 10.f, m_position.y + 10.f);
    // m_diceValueText->setPosition(newPosition);
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