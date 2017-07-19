
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <cstdlib>

#include <SFML/Graphics.hpp>

#include "GoGame.h"
#include "GoGameState.h"
#include "GoGameEngine.h"
#include "GoPlayer.h"
#include "GoPlayerHuman.h"
#include "GoView.h"

static const int GRID_SIZE = 20;
static const int VIEW_WIDTH = 1000;
static const int VIEW_HEIGHT = 600;
static const int FPS = 60;
static const std::string TITLE = "Go AI";

GoGame::GoGame():
    white(new GoPlayerHuman(PlayerColor::WHITE)),
    black(new GoPlayerHuman(PlayerColor::BLACK)),
    state(GRID_SIZE),
    engine(state, *white, *black),
    view(state, TITLE, VIEW_WIDTH, VIEW_HEIGHT, FPS)
{
    debugSetup();
}

GoGame::~GoGame()
{
    delete white;
    delete black;
}

void GoGame::debugSetup()
{
    state.setCell(Coordinate(std::rand() % GRID_SIZE, std::rand() % GRID_SIZE), CellState::BLACK);
    state.setCell(Coordinate(std::rand() % GRID_SIZE, std::rand() % GRID_SIZE), CellState::WHITE);
    state.setCell(Coordinate(std::rand() % GRID_SIZE, std::rand() % GRID_SIZE), CellState::BLACK);
    state.setCell(Coordinate(std::rand() % GRID_SIZE, std::rand() % GRID_SIZE), CellState::WHITE);
    state.setCell(Coordinate(std::rand() % GRID_SIZE, std::rand() % GRID_SIZE), CellState::BLACK);
    state.setCell(Coordinate(std::rand() % GRID_SIZE, std::rand() % GRID_SIZE), CellState::WHITE);
}

/* Helper function for GoGame::play() */
int calculateFrameSleepTime(sf::Time time, int fps)
{
    int timePassed = time.asMilliseconds();
    int sleepTime = (1000.0 / fps) - timePassed;
    if (sleepTime < 0) sleepTime = 0;
    return sleepTime;
}

int GoGame::play()
{
    // Start the event loop
    sf::Clock timer;
    sf::Time lastLoopElapsedTime; // time spent during entire last loop (run time + sleep time)
    while (view.isOpen()) {
        lastLoopElapsedTime = timer.restart();

        std::vector<sf::Event> eventList;
        view.processInput(eventList);
        TEMPrespondToClick(eventList);  // engine.takeTurn(eventList);
        view.updateDisplay();

        // sleep to pad frame time
        sf::Time runTime = timer.getElapsedTime(); // current loop's run time (NO sleep time)
        int sleepTime = calculateFrameSleepTime(runTime, FPS);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
    }

    return EXIT_SUCCESS;
}

void GoGame::TEMPrespondToClick(std::vector<sf::Event> &eventList)
{
    sf::RenderWindow &window = view.getWindow();

    bool &player = state.activePlayer;

    for (sf::Event event : eventList) {
        if (event.type == sf::Event::MouseButtonPressed) {
            Coordinate cpix(event.mouseButton.x, event.mouseButton.y);
            // std::cout << "Clicked pixel: " << cpix << std::endl;

            const int N = state.size;
            const int CELL_WIDTH = (VIEW_WIDTH * GoView::BOARD_VIEW_WIDTH_RATIO - 2 * GoBoardView::PADDING) / (N - 1);
            const int CELL_HEIGHT = (VIEW_HEIGHT - 2 * GoBoardView::PADDING) / (N - 1);

            Coordinate stoneCoords = GoView::mapPixelToGrid(cpix,
                view.getWindow(),
                state,
                VIEW_WIDTH * GoView::BOARD_VIEW_WIDTH_RATIO,
                VIEW_HEIGHT);

            // std::cout << "X: " << stoneCoords.getX() << ", Y: " << stoneCoords.getY() << std::endl;

            // Set player scores to random numbers
            state.setCell(stoneCoords, player ? CellState::WHITE : CellState::BLACK);
            state.white_dead = std::rand() % (30);
            state.black_dead = std::rand() % (25);

            player = !player;
        }
    }
}
