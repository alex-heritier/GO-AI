
#include <iostream>

#include <SFML/Graphics.hpp>

#include "GoBoardView.h"
#include "GoGame.h"
#include "GoGameState.h"

GoBoardView::GoBoardView(sf::RenderWindow &window, const GoGameState &gs, int width, int height):
    window(window),
    goGameState(gs),
    width(width),
    height(height) {}

void GoBoardView::draw()
{
    // Draw board background
    sf::RectangleShape bg(sf::Vector2f(width, height));
    bg.setPosition(0, 0);
    bg.setFillColor(sf::Color(220, 180, 74));
    window.draw(bg);

    // Draw board lines
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

    // Draw stone ghost
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    // Convert pixel to grid then back to pixel so that ghost is consistent with actual stone placement
    Coordinate ghostStoneCoords = GoView::mapGridToPixel(
        GoView::mapPixelToGrid(Coordinate(mousePosition.x, mousePosition.y),
            window,
            goGameState,
            width,
            height),
        window,
        goGameState,
        width,
        height);

    sf::CircleShape ghostStone(CELL_WIDTH / 2);
    ghostStone.setPosition(ghostStoneCoords.getX(), ghostStoneCoords.getY());
    if (goGameState.activePlayer) {
        sf::Color white = sf::Color::White;
        white.a = 0x88;
        ghostStone.setFillColor(white);
    } else {
        sf::Color black = sf::Color::Black;
        black.a = 0x88;
        ghostStone.setFillColor(black);
    }
    window.draw(ghostStone);

    // Draw stones
    for (int i = 0; i < goGameState.grid.size(); i++) {
        const std::vector<CellState> &currentRow = goGameState.grid[i];

        for (int j = 0; j < currentRow.size(); j++) {
            const CellState &currentCell = currentRow[j];

            if (currentCell == CellState::EMPTY)
                continue;

            int x = PADDING + i * CELL_WIDTH - CELL_WIDTH / 2;
            int y = PADDING + (CELL_HEIGHT * N) - (j * CELL_HEIGHT) - CELL_HEIGHT / 2;
            sf::CircleShape stone(CELL_WIDTH / 2);
            stone.setPosition(x, y);

            if (currentCell == CellState::BLACK) {
                stone.setFillColor(sf::Color::Black);
            } else if (currentCell == CellState::WHITE) {
                stone.setFillColor(sf::Color::White);
            }
            window.draw(stone);
        }
    }
}
