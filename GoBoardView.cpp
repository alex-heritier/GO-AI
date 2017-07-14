
#include <iostream>

#include <SFML/Graphics.hpp>

#include "GoBoardView.h"
#include "GoGameState.h"

GoBoardView::GoBoardView(const GoGameState &gs): goGameState(gs) {}

void GoBoardView::draw(sf::RenderWindow &window, int width, int height)
{
    // Draw board background
    sf::RectangleShape bg(sf::Vector2f(width, height));
    bg.setPosition({0, 0});
    bg.setFillColor(sf::Color(220, 180, 74));
    window.draw(bg);

    // Draw board lines
    const int PADDING = 12;
    const int N = goGameState.size;
    const int CELL_WIDTH = (width - 2 * PADDING) / N;
    const int CELL_HEIGHT = (height - 2 * PADDING) / N;
    const int LINE_COUNT = 2 * (N + 1);

    // Draw vertical lines
    sf::Vertex verticalLines[LINE_COUNT];
    for (int i = 0; i < N + 1; i++) {
        verticalLines[2 * i] = sf::Vertex(sf::Vector2f(PADDING + CELL_WIDTH * i, PADDING), sf::Color::Black);
        verticalLines[2 * i + 1] = sf::Vertex(sf::Vector2f(PADDING + CELL_WIDTH * i, PADDING + CELL_HEIGHT * N), sf::Color::Black);
    }
    window.draw(verticalLines, LINE_COUNT, sf::Lines);

    // Draw horizontal lines
    sf::Vertex horizontalLines[LINE_COUNT];
    for (int i = 0; i < N + 1; i++) {
        horizontalLines[2 * i] = sf::Vertex(sf::Vector2f(PADDING, PADDING + CELL_HEIGHT * i), sf::Color::Black);
        horizontalLines[2 * i + 1] = sf::Vertex(sf::Vector2f(PADDING + CELL_WIDTH * N, PADDING + CELL_HEIGHT * i), sf::Color::Black);
    }
    window.draw(horizontalLines, LINE_COUNT, sf::Lines);
}
