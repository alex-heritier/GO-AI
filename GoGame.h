#ifndef GO_GAME_H
#define GO_GAME_H

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Coordinate.h"
#include "GoPlayer.h"
#include "GoGameState.h"
#include "GoGameEngine.h"
#include "GoView.h"

class GoGame {
public:
    GoGame();
    ~GoGame();
    int play();
    void end();
    static Coordinate mapPixelToGrid(const Coordinate &coord, const sf::RenderWindow &window, const GoGameState &state);
    static Coordinate mapGridToPixel(const Coordinate &coord, const sf::RenderWindow &window, const GoGameState &state);
private:
    GoPlayer *const white;
    GoPlayer *const black;
    GoGameState state;
    GoGameEngine engine;
    GoView view;

    void debugSetup();
    void TEMPrespondToClick(std::vector<sf::Event> &eventList);
};

#endif
