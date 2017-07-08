#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {
public:
    Coordinate(int x, int y);
    int getX() const;
    int getY() const;
    void setX(int);
    void setY(int);

private:
    int x;
    int y;
};

#endif