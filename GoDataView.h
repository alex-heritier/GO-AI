
#ifndef GO_DATA_VIEW_H
#define GO_DATA_VIEW_H

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Coordinate.h"
#include "GoGameState.h"

class GoDataView {
public:
    // Data
    static const std::string FONT_FILE;

    // Methods
    GoDataView(sf::RenderWindow &window, const GoGameState &gs, int width, int height);
    void draw();
private:
    sf::RenderWindow &window;
    const GoGameState &goGameState;
    const int width;
    const int height;
};

#endif
