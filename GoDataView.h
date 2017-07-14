
#ifndef GO_DATA_VIEW_H
#define GO_DATA_VIEW_H

#include <iostream>

#include <SFML/Graphics.hpp>

#include "GoGameState.h"

class GoDataView {
public:
    GoDataView(const GoGameState &gs);
    void draw(sf::RenderWindow &window, int width, int height);
private:
    const GoGameState &goGameState;
};

#endif
