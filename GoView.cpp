
#include <iostream>

#include <SFML/Graphics.hpp>

#include "GoView.h"
#include "GoBoardView.h"
#include "GoDataView.h"
#include "Utility.h"

static const float BOARD_VIEW_WIDTH_RATIO = 0.6;
static const float DATA_VIEW_WIDTH_RATIO = 1 - BOARD_VIEW_WIDTH_RATIO;

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
    sf::View v1(sf::FloatRect(0, 0, 0.6 * width, height));
    v1.setViewport(sf::FloatRect(0, 0, 0.6f, 1));
    window.setView(v1);
    boardView.draw();

    // draw the game data
    sf::View v2(sf::FloatRect(0, 0, 0.4 * width, height));
    v2.setViewport(sf::FloatRect(0.6f, 0, 0.4f, 1));
    window.setView(v2);
    dataView.draw();

    window.setView(window.getDefaultView());
    window.display();
}

void GoView::end()
{
    window.close();
}
