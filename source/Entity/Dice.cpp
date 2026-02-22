#include "Entity/Dice.h"

Dice::Dice()
    : m_timer(m_game->getTimerManager().createTimer())
{

  makeFaceValues();
  // Timer
  m_timer->onTimeout = [this]()
  { onTimeout(); };
}
Dice::~Dice() {}

void Dice::update(sf::Time &delta)
{
  if (!m_timer->getIsStopped())
  {
    m_timer->update(delta);
    int diceValue = randomHelper::GET_RANDOM_NUMBER_INT(1, m_faces);
  }
  if (m_timer->getIsStopped())
  {
    m_elapsedTime += delta;
    if (m_elapsedTime.asSeconds() >= 0.5f)
    {
      m_timer->toggleIsStopped();
      m_elapsedTime = sf::Time::Zero;
    }
  }
}

void Dice::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(*m_timer);
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

void Dice::setFaces(size_t faces)
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
  m_timer->setCooldown(cooldown);
}
void Dice::setFaceValues(const std::map<int, float> &faceValues)
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

void Dice::setPosition(const sf::Vector2f &position)
{
  VertexRectangleDrawable::setVertexBodyPosition(position);
}

void Dice::onTimeout()
{
  m_timer->toggleIsStopped();
}

const std::string &Dice::getName() const
{
  return m_name;
}

const std::string &Dice::getStats() const
{

  std::stringstream coolDownStream;
  coolDownStream << std::fixed << std::setprecision(2) << m_timer->getCoolDown();

  return "Faces: " +
         std::to_string(m_faces) +
         "\n"
         "Rerolls: " +
         std::to_string(m_rerolls) +
         "\n"
         "CoolDown: " +
         coolDownStream.str();
}

const sf::FloatRect &Dice::getGlobalBounds() const
{
  return VertexRectangleDrawable::getGlobalBounds();
}

const sf::Vector2f &Dice::getPosition() const
{
  return VertexRectangleDrawable::getVertexBodyCenter();
}