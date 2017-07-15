
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

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
GoView::GoView(const GoGameState &gs, const std::string &t, int w, int h):
    window(sf::VideoMode(w, h), t),
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

int GoView::run()
{
    // Start the event loop
    sf::Clock timer;
    sf::Time lastLoopElapsedTime; // time spent during entire last loop (run time + sleep time)
    while (window.isOpen()) {
        lastLoopElapsedTime = timer.restart();

        std::vector<sf::Event> eventList;
        processInput(eventList);
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
