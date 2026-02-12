#include "Entity/Dice.h"

Dice::Dice()
    : Dice(
          4,
          1,
          2)
{
}

Dice::Dice(int faces, int rerolls, float cooldown)
    : VertexRectangle(
          0,
          0,
          960 + (configLoader::getInteger("ASSETS_TILE_SIZE") * randomHelper::GET_RANDOM_NUMBER_INT(0, 5)),
          1312),
      m_timer(cooldown),
      m_faces(faces),
      m_rerolls(rerolls),
      m_stop(false),
      m_isOnFloor(false)
{
  // Dice
  makeFaceValues();

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
    int diceValue = randomHelper::GET_RANDOM_NUMBER_INT(1, m_faces);
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
  m_diceWeaponSlotMenu.getShape().setPointCount(m_faces);
  m_diceSacMenu.getShape().setPointCount(m_faces);
  m_diceFloorItem.getShape().setPointCount(m_faces);
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

void Dice::setIsOnFloor(bool isOnFloor)
{
  m_isOnFloor = isOnFloor;
}

void Dice::onTimeout()
{
  m_timer.toggleStop();
  toggleStop();
}