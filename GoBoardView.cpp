
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
    const int N = goGameState.size - 1;
    const int CELL_WIDTH = (width - 2 * BASE_PADDING) / N;
    const int CELL_HEIGHT = (height - 2 * BASE_PADDING) / N;
    const int GRID_WIDTH = CELL_WIDTH * N;
    const int GRID_HEIGHT = CELL_HEIGHT * N;
    const int X_PADDING = getXPadding(N, width);
    const int Y_PADDING = getYPadding(N, height);
    const int TOTAL_X_PAD = BASE_PADDING + X_PADDING;
    const int TOTAL_Y_PAD = BASE_PADDING + Y_PADDING;
    const int VERTEX_COUNT = 2 * (N + 1);

    // Draw vertical lines
    sf::Vertex verticalLines[VERTEX_COUNT];
    for (int i = 0; i < (N + 1); i++) {
        verticalLines[2 * i] = sf::Vertex(sf::Vector2f(TOTAL_X_PAD + CELL_WIDTH * i, TOTAL_Y_PAD), sf::Color::Black);
        verticalLines[2 * i + 1] = sf::Vertex(sf::Vector2f(TOTAL_X_PAD + CELL_WIDTH * i, TOTAL_Y_PAD + GRID_HEIGHT), sf::Color::Black);
    }
    window.draw(verticalLines, VERTEX_COUNT, sf::Lines);

    // Draw horizontal lines
    sf::Vertex horizontalLines[VERTEX_COUNT];
    for (int i = 0; i < (N + 1); i++) {
        horizontalLines[2 * i] = sf::Vertex(sf::Vector2f(TOTAL_X_PAD, TOTAL_Y_PAD + CELL_HEIGHT * i), sf::Color::Black);
        horizontalLines[2 * i + 1] = sf::Vertex(sf::Vector2f(TOTAL_X_PAD + GRID_WIDTH, TOTAL_Y_PAD + CELL_HEIGHT * i), sf::Color::Black);
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

    const int opacity = 0x88;
    sf::CircleShape ghostStone(CELL_WIDTH / 2);
    ghostStone.setPosition(ghostStoneCoords.getX(), ghostStoneCoords.getY());
    if (goGameState.activePlayer) {
        sf::Color white = sf::Color::White;
        white.a = opacity;
        ghostStone.setFillColor(white);
    } else {
        sf::Color black = sf::Color::Black;
        black.a = opacity;
        ghostStone.setFillColor(black);
    }
    sf::Color ghostOutlineColor = sf::Color::Black;
    ghostOutlineColor.a = opacity;
    ghostStone.setOutlineColor(ghostOutlineColor);
    ghostStone.setOutlineThickness(-1.5);
    window.draw(ghostStone);

    // Draw stones
    for (int i = 0; i < goGameState.size; i++) {
        for (int j = 0; j < goGameState.size; j++) {
            const CellState &currentCell = goGameState.getCell(Coordinate(i, j));

            if (currentCell == CellState::EMPTY)
                continue;

            int x = TOTAL_X_PAD + i * CELL_WIDTH - CELL_WIDTH / 2;
            int y = TOTAL_Y_PAD + GRID_HEIGHT - (j * CELL_HEIGHT) - CELL_HEIGHT / 2;
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

int GoBoardView::getXPadding(int N, int width)
{
    const int CELL_WIDTH = (width - 2 * BASE_PADDING) / N;
    const int GRID_WIDTH = CELL_WIDTH * N;
    return (width - (2 * BASE_PADDING + GRID_WIDTH)) / 2;
}

int GoBoardView::getYPadding(int N, int height)
{
    const int CELL_HEIGHT = (height - 2 * BASE_PADDING) / N;
    const int GRID_HEIGHT = CELL_HEIGHT * N;
    return (height - (2 * BASE_PADDING + GRID_HEIGHT)) / 2;
}
