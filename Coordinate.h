#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>

class Coordinate {
public:
    Coordinate(int x, int y);
    int getX() const;
    int getY() const;
    void setX(int);
    void setY(int);
    Coordinate &operator=(const Coordinate &coord);
private:
    int x;
    int y;
};

std::ostream &operator<<(std::ostream &out, const Coordinate &coord);

#endif
