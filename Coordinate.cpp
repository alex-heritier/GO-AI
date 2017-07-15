
#include <iostream>

#include "Coordinate.h"

Coordinate::Coordinate(int x, int y): x(x), y(y) {}

int Coordinate::getX() const { return x; }
int Coordinate::getY() const { return y; }

void Coordinate::setX(int x) { Coordinate::x = x; }
void Coordinate::setY(int y) { Coordinate::y = y; }

Coordinate &Coordinate::operator=(const Coordinate &coord)
{
    setX(coord.x);
    setY(coord.y);

    return *this;
}

std::ostream &operator<<(std::ostream& out, const Coordinate &coord) {
    out << "(" << coord.getX() << ", " << coord.getY() << ")";
    return out;
 }
