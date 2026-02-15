#include "Entity/Cell.h"

using namespace std;

Cell::Cell(
    int left,
    int top,
    int assetsLeft,
    int assetsTop)
    : VertexRectangle(
          left,
          top,
          assetsLeft,
          assetsTop) {}

Cell::~Cell() {}