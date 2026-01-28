#include <SFML/Graphics.hpp>
#include "Event/HeroEvents.h"
#include "Entity/Hero.h"
#include "_ENUMS.h"

HeroEvents::HeroEvents(Hero &hero)
    : m_hero(hero) {};
HeroEvents::~HeroEvents() {};

void HeroEvents::keyPressed()
{
}
