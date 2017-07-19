
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
    const int CELL_WIDTH = (width - 2 * PADDING) / (N - 1);
    const int CELL_HEIGHT = (height - 2 * PADDING) / (N - 1);
    const int VERTEX_COUNT = 2 * N;

    // Draw vertical lines
    sf::Vertex verticalLines[VERTEX_COUNT];
    for (int i = 0; i < N; i++) {
        verticalLines[2 * i] = sf::Vertex(sf::Vector2f(PADDING + CELL_WIDTH * i, PADDING), sf::Color::Black);
        verticalLines[2 * i + 1] = sf::Vertex(sf::Vector2f(PADDING + CELL_WIDTH * i, PADDING + CELL_HEIGHT * (N - 1)), sf::Color::Black);
    }
    window.draw(verticalLines, VERTEX_COUNT, sf::Lines);

    // Draw horizontal lines
    sf::Vertex horizontalLines[VERTEX_COUNT];
    for (int i = 0; i < N; i++) {
        horizontalLines[2 * i] = sf::Vertex(sf::Vector2f(PADDING, PADDING + CELL_HEIGHT * i), sf::Color::Black);
        horizontalLines[2 * i + 1] = sf::Vertex(sf::Vector2f(PADDING + CELL_WIDTH * (N - 1), PADDING + CELL_HEIGHT * i), sf::Color::Black);
    }
    window.draw(horizontalLines, VERTEX_COUNT, sf::Lines);

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
    for (int i = 0; i < goGameState.size; i++) {
        for (int j = 0; j < goGameState.size; j++) {
            const CellState &currentCell = goGameState.getCell(Coordinate(i, j));

            if (currentCell == CellState::EMPTY)
                continue;

            int x = PADDING + i * CELL_WIDTH - CELL_WIDTH / 2;
            int y = PADDING + (CELL_HEIGHT * (N - 1)) - (j * CELL_HEIGHT) - CELL_HEIGHT / 2;
            sf::CircleShape stone(CELL_WIDTH / 2);
            stone.setPosition(x, y);

            if (currentCell == CellState::BLACK) {
                stone.setFillColor(sf::Color::Black);
            } else if (currentCell == CellState::WHITE) {
                stone.setFillColor(sf::Color::White);
            }
            sf::Color outlineColor(0x00, 0x00, 0x00);
            stone.setOutlineColor(outlineColor);
            stone.setOutlineThickness(-1.5);
            window.draw(stone);
        }
    }
}
