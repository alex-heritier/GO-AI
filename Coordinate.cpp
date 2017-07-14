
#include "Coordinate.h"

Coordinate::Coordinate(int x, int y): x(x), y(y) {}

int Coordinate::getX() const { return x; }
int Coordinate::getY() const { return y; }

void Coordinate::setX(int x) { Coordinate::x = x; }
void Coordinate::setY(int y) { Coordinate::y = y; }

Coordinate &Coordinate::operator=(const Coordinate &coord)
{
    x = coord.x;
    y = coord.y;

    return *this;
}
