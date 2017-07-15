#ifndef GOVIEW_H
#define GOVIEW_H

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "GoBoardView.h"
#include "GoDataView.h"
#include "GoGameState.h"

class GoView {
public:
    GoView(const GoGameState &gs, const std::string &title, int width, int height);
    int run();
    void end();
private:
    // data
    sf::RenderWindow window;
    const GoGameState &goGameState;
    std::string title;
    int width;
    int height;
    const int fps;
    GoBoardView boardView;
    GoDataView dataView;

    // methods
    void processInput(std::vector<sf::Event> &eventList);
    void updateDisplay();
};

#endif
