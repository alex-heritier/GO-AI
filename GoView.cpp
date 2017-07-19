
#include <iostream>

#include <SFML/Graphics.hpp>

#include "GoView.h"
#include "GoBoardView.h"
#include "GoDataView.h"
#include "Utility.h"

/* Class methods */
GoView::GoView(const GoGameState &gs, const std::string &t, int w, int h, int fps):
    window(sf::VideoMode(w, h), t),
    goGameState(gs),
    title(t),
    width(w),
    height(h),
    fps(fps),
    boardView(window, gs, BOARD_VIEW_WIDTH_RATIO * width, height),
    dataView(window, gs, DATA_VIEW_WIDTH_RATIO * width, height) {}


sf::RenderWindow &GoView::getWindow()
{
    return window;
}

bool GoView::isOpen() const
{
    return window.isOpen();
}

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

        // add event to eventList
        eventList.push_back(event);
    }
}

void GoView::updateDisplay()
{
    window.clear();

    // draw the Go board
    sf::View v1(sf::FloatRect(0, 0, BOARD_VIEW_WIDTH_RATIO * width, height));
    v1.setViewport(sf::FloatRect(0, 0, BOARD_VIEW_WIDTH_RATIO, 1));
    window.setView(v1);
    boardView.draw();

    // draw the game data
    sf::View v2(sf::FloatRect(0, 0, DATA_VIEW_WIDTH_RATIO * width, height));
    v2.setViewport(sf::FloatRect(BOARD_VIEW_WIDTH_RATIO, 0, DATA_VIEW_WIDTH_RATIO, 1));
    window.setView(v2);
    dataView.draw();

    window.setView(window.getDefaultView());
    window.display();
}

void GoView::end()
{
    window.close();
}


Coordinate GoView::mapPixelToGrid(const Coordinate &coord,
    const sf::RenderWindow &window, const GoGameState &state, int width, int height)
{
    // std::cout << "mapPixelToGrid" << std::endl;
    const int N = state.size - 1;
    const int CELL_WIDTH = (width - 2 * GoBoardView::BASE_PADDING) / N;
    const int CELL_HEIGHT = (height - 2 * GoBoardView::BASE_PADDING) / N;
    const int GRID_WIDTH = CELL_WIDTH * N;
    const int GRID_HEIGHT = CELL_HEIGHT * N;
    const int X_PADDING = GoBoardView::getXPadding(N, width);
    const int Y_PADDING = GoBoardView::getYPadding(N, height);
    const int TOTAL_X_PAD = GoBoardView::BASE_PADDING + X_PADDING;
    const int TOTAL_Y_PAD = GoBoardView::BASE_PADDING + Y_PADDING;

    sf::Vector2f adjustedPixel(window.mapPixelToCoords(sf::Vector2i(coord.getX(), coord.getY())));
    // std::cout << "Adjusted pixel: (" << adjustedPixel.x << ", " << adjustedPixel.y << ")" << std::endl;
    Coordinate cpix(adjustedPixel.x, adjustedPixel.y);

    int x = (cpix.getX() - TOTAL_X_PAD + (CELL_WIDTH / 2)) / CELL_WIDTH ;
    int y = ((height - cpix.getY() - TOTAL_Y_PAD + (CELL_HEIGHT / 2)) / CELL_HEIGHT);

    if (x < 0)
        x = 0;
    else if (x >= state.size)
        x = state.size - 1;

    if (y < 0)
        y = 0;
    else if (y >= state.size)
        y = state.size - 1;

    // std::cout << "X: " << x << ", Y: " << y << std::endl;
    return Coordinate(x, y);
}

Coordinate GoView::mapGridToPixel(const Coordinate &coord,
    const sf::RenderWindow &window, const GoGameState &state, int width, int height)
{
    // std::cout << "mapGridToPixel" << std::endl;
    const int N = state.size - 1;
    const int CELL_WIDTH = (width - 2 * GoBoardView::BASE_PADDING) / N;
    const int CELL_HEIGHT = (height - 2 * GoBoardView::BASE_PADDING) / N;
    const int X_PADDING = GoBoardView::getXPadding(N, width);
    const int Y_PADDING = GoBoardView::getYPadding(N, height);
    const int TOTAL_X_PAD = GoBoardView::BASE_PADDING + X_PADDING;
    const int TOTAL_Y_PAD = GoBoardView::BASE_PADDING + Y_PADDING;

    // std::cout << "Moused-over pixel: " << cpix << std::endl;

    int x = coord.getX() * CELL_WIDTH + TOTAL_X_PAD - CELL_WIDTH / 2;
    int y = TOTAL_Y_PAD + (N - coord.getY()) * CELL_HEIGHT - CELL_HEIGHT / 2;

    // std::cout << "X: " << x << ", Y: " << y << std::endl;

    return Coordinate(x, y);
}
