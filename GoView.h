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
    // Data
    static constexpr float BOARD_VIEW_WIDTH_RATIO = 0.6;
    static constexpr float DATA_VIEW_WIDTH_RATIO = BOARD_VIEW_WIDTH_RATIO - 0.4;

    // Methods
    GoView(const GoGameState &gs, const std::string &title, int width, int height, int fps);
    void end();
    void processInput(std::vector<sf::Event> &eventList);
    void updateDisplay();
    bool isOpen() const;
    sf::RenderWindow &getWindow();

    static Coordinate mapPixelToGrid(const Coordinate &coord,
        const sf::RenderWindow &win, const GoGameState &gs, int w, int h);
    static Coordinate mapGridToPixel(const Coordinate &coord,
        const sf::RenderWindow &win, const GoGameState &gs, int w, int h);
private:
    // Data
    sf::RenderWindow window;
    const GoGameState &goGameState;
    std::string title;
    int width;
    int height;
    const int fps;
    GoBoardView boardView;
    GoDataView dataView;

    // Methods
    void TEMPrespondToClick(sf::Event &event);
};

#endif
