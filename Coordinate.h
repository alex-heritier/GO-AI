#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>
#include <vector>

using namespace std;

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

using Coordinates = vector<Coordinate>;

std::ostream &operator<<(std::ostream &out, const Coordinate &coord);

#endif
