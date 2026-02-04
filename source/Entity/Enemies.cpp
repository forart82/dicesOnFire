#include "Entity/Enemies.h"

Enemies::Enemies()
{
  m_vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
  makeVertices();
}

Enemies::~Enemies() {}

void Enemies::update(sf::Time &delta)
{

  for (auto &enemy : m_enemies)
  {
    enemy->update(delta);
  }
  makeVertices();
}

void Enemies::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  states.texture = &textureManager::getTexture("Utumno");
  for (auto &enemy : m_enemies)
  {
    target.draw(*enemy, states);
  }
  target.draw(m_vertices, states);
}

void Enemies::addEnemy(Hero &hero)
{
  m_enemies.emplace_back(enemyHelper::CREATE_ENEMY(hero));
}

void Enemies::removeEnemyOnDeath()
{
  m_enemies.erase(
      std::remove_if(
          m_enemies.begin(),
          m_enemies.end(),
          [](const auto &enemy)
          {
            return enemy->getHealth() <= 0;
          }),
      m_enemies.end());
}

void Enemies::makeVertices()
{
  if (m_vertices.getVertexCount() != m_enemies.size() * 6)
  {
    m_vertices.resize(m_enemies.size() * 6);
  }

  int enemyCounter = 0;
  for (auto &enemy : m_enemies)
  {
    sf::Vertex *triangels = &m_vertices[enemyCounter * 6];
    triangels[0].position = enemy->getLeftTop();
    triangels[1].position = enemy->getRightTop();
    triangels[2].position = enemy->getLeftBottom();

    // Triangle 2
    triangels[3].position = enemy->getRightTop();
    triangels[4].position = enemy->getRightBottom();
    triangels[5].position = enemy->getLeftBottom();

    triangels[0].texCoords = enemy->getAssetsLeftTop();
    triangels[1].texCoords = enemy->getAssetsRightTop();
    triangels[2].texCoords = enemy->getAssetsLeftBottom();

    // Triangle 2
    triangels[3].texCoords = enemy->getAssetsRightTop();
    triangels[4].texCoords = enemy->getAssetsRightBottom();
    triangels[5].texCoords = enemy->getAssetsLeftBottom();

    enemyCounter++;
  }
}

const std::vector<std::unique_ptr<Enemy>> &Enemies::getEnemies() const
{
  return m_enemies;
}