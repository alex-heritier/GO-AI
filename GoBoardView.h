
#ifndef GO_BOARD_VIEW_H
#define GO_BOARD_VIEW_H

#include <iostream>

#include <SFML/Graphics.hpp>

#include "GoGameState.h"

class GoBoardView {
public:
    GoBoardView(const GoGameState &gs);
    void draw(sf::RenderWindow &window, int width, int height);
private:
    const GoGameState &goGameState;
};

#endif
