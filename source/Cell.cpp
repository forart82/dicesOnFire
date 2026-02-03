#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cell.h"
#include "_GLOBALS.h"
#include "_HELPERS.h"
#include "Manager/TextureManager.h"

using namespace std;

Cell::Cell(
    int left,
    int top)
    : VertexRectangle(
          left,
          top,
          32 * helper::GET_RANDOM_NUMBER_INT(0, 10),
          224) {}

Cell::~Cell() {}