
#ifndef GO_BOARD_VIEW_H
#define GO_BOARD_VIEW_H

#include <iostream>

#include <SFML/Graphics.hpp>

#include "GoGameState.h"

class GoBoardView {
public:
    // Data
    static const int BASE_PADDING = 30;

    // Methods
    GoBoardView(sf::RenderWindow &window, const GoGameState &gs, int width, int height);
    void draw();

    static int getXPadding(int n, int w);
    static int getYPadding(int n, int h);
private:
    // Data
    sf::RenderWindow &window;
    const GoGameState &goGameState;
    const int width;
    const int height;
};

#endif
