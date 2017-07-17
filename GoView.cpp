
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <cstdlib>

#include <SFML/Graphics.hpp>

#include "GoView.h"
#include "GoBoardView.h"
#include "GoDataView.h"
#include "Utility.h"

/* Helper functions */
int calculateFrameSleepTime(sf::Time time, int fps)
{
    int timePassed = time.asMilliseconds();
    int sleepTime = (1000.0 / fps) - timePassed;
    if (sleepTime < 0) sleepTime = 0;
    return sleepTime;
}

/* Class methods */
GoView::GoView(GoGameState &gs, const std::string &t, int w, int h):
    window(sf::VideoMode(w, h), t),
    goGameState(gs),
    title(t),
    width(w),
    height(h),
    fps(60),
    boardView(gs),
    dataView(gs) {}

void GoView::processInput(std::vector<sf::Event> &eventList)
{
    // Process events
    sf::Event event;
    while (window.pollEvent(event))
    {
        // close window
        if (event.type == sf::Event::Closed
            || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
            Logger(LogType::INFO).put("Window being closed from GoView.");
            window.close();
            return;
        }

        TEMPrespondToClick(event);

        // add event to eventList
        eventList.push_back(event);
    }
}

void GoView::updateDisplay()
{
    window.clear();

    // draw the Go board
    sf::View v1(sf::FloatRect(0, 0, 0.6 * width, height));
    v1.setViewport(sf::FloatRect(0, 0, 0.6f, 1));
    window.setView(v1);
    boardView.draw(window, 0.6 * width, height);

    // draw the game data
    sf::View v2(sf::FloatRect(0, 0, 0.4 * width, height));
    v2.setViewport(sf::FloatRect(0.6f, 0, 0.4f, 1));
    window.setView(v2);
    dataView.draw(window, 0.4 * width, height);

    window.setView(window.getDefaultView());
    window.display();
}

void GoView::TEMPrespondToClick(sf::Event &event)
{
    static bool player = false;

    if (event.type == sf::Event::MouseButtonPressed) {
        goGameState.clickedPixel = Coordinate(event.mouseButton.x, event.mouseButton.y);
        Coordinate &cpix = goGameState.clickedPixel;
        std::cout << "Clicked pixel: " << goGameState.clickedPixel << std::endl;

        const int PADDING = 20;
        const int N = goGameState.size;
        const int CELL_WIDTH = (600 - 2 * PADDING) / N;
        const int CELL_HEIGHT = (600 - 2 * PADDING) / N;
        const int BIAS = 3; // adjusts the y coordinate slightly for more accuracy

        sf::Vector2f adjustedPixel(window.mapPixelToCoords(sf::Vector2i(cpix.getX(), cpix.getY())));
        std::cout << "Adjusted pixel: (" << adjustedPixel.x << ", " << adjustedPixel.y << ")" << std::endl;
        cpix.setX(adjustedPixel.x);
        cpix.setY(adjustedPixel.y);

        int x = (cpix.getX() - PADDING + (CELL_WIDTH / 2)) / CELL_WIDTH ;
        int y = ((600 - cpix.getY() - PADDING + (CELL_HEIGHT / 2) - BIAS) / CELL_HEIGHT);

        std::cout << "X: " << x << ", Y: " << y << std::endl;

        if (x < 0)
            x = 0;
        else if (x >= goGameState.size)
            x = goGameState.size;

        if (y < 0)
            y = 0;
        else if (y >= goGameState.size)
            y = goGameState.size;

        Coordinate coord(x, y);

        std::cout << "X: " << x << ", Y: " << y << std::endl;

        goGameState.setCell(coord, player ? CellState::WHITE : CellState::BLACK);
        goGameState.white_dead = std::rand() % (N * N);
        goGameState.black_dead = std::rand() % (N * N);

        player = !player;
    }
}

int GoView::run()
{
    // Start the event loop
    sf::Clock timer;
    sf::Time lastLoopElapsedTime; // time spent during entire last loop (run time + sleep time)
    while (window.isOpen()) {
        lastLoopElapsedTime = timer.restart();

        std::vector<sf::Event> eventList;
        processInput(eventList);
        //respondToInput(eventList);
        updateDisplay();

        // sleep to pad frame time
        sf::Time runTime = timer.getElapsedTime(); // current loop's run time (NO sleep time)
        int sleepTime = calculateFrameSleepTime(runTime, fps);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
    }

    return EXIT_SUCCESS;
}

void GoView::end()
{
    window.close();
}
