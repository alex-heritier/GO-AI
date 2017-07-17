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
    GoView(const GoGameState &gs, const std::string &title, int width, int height, int fps);
    void end();
    sf::RenderWindow &getWindow();
    bool isOpen() const;
    void processInput(std::vector<sf::Event> &eventList);
    void updateDisplay();
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
    void TEMPrespondToClick(sf::Event &event);
};

#endif
