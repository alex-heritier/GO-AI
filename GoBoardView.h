
#ifndef GO_BOARD_VIEW_H
#define GO_BOARD_VIEW_H

#include <iostream>

#include <SFML/Graphics.hpp>

#include "GoGameState.h"

class GoBoardView {
public:
    GoBoardView(sf::RenderWindow &window, const GoGameState &gs, int width, int height);
    void draw();
private:
    sf::RenderWindow &window;
    const GoGameState &goGameState;
    const int width;
    const int height;

    Coordinate snapPixelToBoard(int x, int y);
};

#endif
