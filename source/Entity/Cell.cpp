#include "Entity/Cell.h"

using namespace std;

Cell::Cell(
    int left,
    int top)
    : VertexRectangle(
          left,
          top,
          32 * randomHelper::GET_RANDOM_NUMBER_INT(0, 10),
          224) {}

Cell::~Cell() {}