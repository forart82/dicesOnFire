#ifndef _POSITIONS_H
#define _POSITIONS_H

#include <SFML/Graphics.hpp>
#include <map>
#include "_COLORS.h"

namespace gui
{

  struct WeaponSlot
  {
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color color;
    sf::Vector2f timerOuterPosition;
    sf::Vector2f timerOuterSize;
    sf::Color outerColor;
    sf::Vector2f timerInnerPosition;
    sf::Vector2f timerInnerSize;
    sf::Color innerColor;
  };

  inline const sf::Vector2f WEAPONSLOTMENU_POSITION = sf::Vector2f(400.f, 800.f);
  inline const sf::Vector2f WEAPONSLOTMENU_SIZE = sf::Vector2f(800.f, 1600.f);

  inline const std::map<int, WeaponSlot> WEAPONSLOTS = {
      {1,
       {
           sf::Vector2f(390.f, 100.f), // position
           sf::Vector2f(760.f, 180.f), // size
           sf::Vector2f(400.f, 160.f), // timerOuterPosition
           sf::Vector2f(740.f, 40.f),  // timerOuterSize
           sf::Vector2f(400.f, 160.f), // timerInnerPosition
           sf::Vector2f(720.f, 20.f),

       }}, // timerInnerSize

      {2,
       {
           sf::Vector2f(390.f, 290.f), // position
           sf::Vector2f(760.f, 180.f), // size
           sf::Vector2f(400.f, 350.f), // timerOuterPosition
           sf::Vector2f(740.f, 40.f),  // timerOuterSize
           sf::Vector2f(400.f, 350.f), // timerInnerPosition
           sf::Vector2f(720.f, 20.f),

       }}, // timerInnerSize
      {3,
       {
           sf::Vector2f(390.f, 480.f), // position
           sf::Vector2f(760.f, 180.f), // size
           sf::Vector2f(400.f, 540.f), // timerOuterPosition
           sf::Vector2f(740.f, 40.f),  // timerOuterSize
           sf::Vector2f(400.f, 540.f), // timerInnerPosition
           sf::Vector2f(720.f, 20.f),

       }}, // timerInnerSize
      {4,
       {
           sf::Vector2f(390.f, 670.f), // position
           sf::Vector2f(760.f, 180.f), // size
           sf::Vector2f(400.f, 730.f), // timerOuterPosition
           sf::Vector2f(740.f, 40.f),  // timerOuterSize
           sf::Vector2f(400.f, 730.f), // timerInnerPosition
           sf::Vector2f(720.f, 20.f),

       }}, // timerInnerSize
      {5,
       {
           sf::Vector2f(390.f, 860.f), // position
           sf::Vector2f(760.f, 180.f), // size
           sf::Vector2f(400.f, 920.f), // timerOuterPosition
           sf::Vector2f(740.f, 40.f),  // timerOuterSize
           sf::Vector2f(400.f, 920.f), // timerInnerPosition
           sf::Vector2f(720.f, 20.f),

       }}, // timerInnerSize
      {6,
       {
           sf::Vector2f(390.f, 1050.f), // position
           sf::Vector2f(760.f, 180.f),  // size
           sf::Vector2f(400.f, 1110.f), // timerOuterPosition
           sf::Vector2f(740.f, 40.f),   // timerOuterSize
           sf::Vector2f(400.f, 1110.f), // timerInnerPosition
           sf::Vector2f(720.f, 20.f),

       }}, // timerInnerSize
      {7,
       {
           sf::Vector2f(390.f, 1240.f), // position
           sf::Vector2f(760.f, 180.f),  // size
           sf::Vector2f(400.f, 1300.f), // timerOuterPosition
           sf::Vector2f(740.f, 40.f),   // timerOuterSize
           sf::Vector2f(400.f, 1300.f), // timerInnerPosition
           sf::Vector2f(720.f, 20.f),

       }}, // timerInnerSize
      {8,
       {
           sf::Vector2f(390.f, 1430.f), // position
           sf::Vector2f(760.f, 180.f),  // size
           sf::Vector2f(400.f, 1490.f), // timerOuterPosition
           sf::Vector2f(740.f, 40.f),   // timerOuterSize
           sf::Vector2f(400.f, 1490.f), // timerInnerPosition
           sf::Vector2f(720.f, 20.f),

       }}, // timerInnerSize
  };

  inline const std::map <

};
#endif