#include <iostream>
#include <string>

#include "GoGameState.h"

GoGameState::GoGameState(int size):
   size(size), white_dead(0), black_dead(0), clickedPixel(0, 0) {
    for (int i = 0; i < size; i++) {
        grid.push_back(std::vector<CellState>());
        for (int j = 0; j < size; j++) {
            grid[i].push_back(CellState::EMPTY);
        }
    }
}

/*
 set cell pointed to by 'coord' to value 'cs'
 RETURN: returns old cell state
 */
CellState GoGameState::setCell(const Coordinate &coord, const CellState cs)
{
    int x = coord.getX();
    int y = coord.getY();

    if (x < 0 || x >= size || y < 0 || y >= size) {
        std::cerr << "ERROR: GoGameState::setCell - coordinates out of bounds" << std::endl;
    }

    CellState oldState = grid[x][y];
    grid[x][y] = cs;

    return oldState;
}

/*
 RETURN: get cell value at 'coord'
 */
CellState GoGameState::getCell(const Coordinate &coord) const
{
    int x = coord.getX();
    int y = coord.getY();

    if (x < 0 || x >= size || y < 0 || y >= size) {
        std::cerr << "ERROR: GoGameState::setCell - coordinates out of bounds" << std::endl;
    }

    return grid[x][y];
}

/*
 kill white cell
 */
void GoGameState::killWhite() { white_dead++; }

/*
 kill black cell
 */
void GoGameState::killBlack() { black_dead++; }

/*
 RETURN: get white cell dead count
 */
int GoGameState::getWhiteDead() const { return white_dead; }

/*
 RETURN: get black cell dead count
 */
int GoGameState::getBlackDead() const { return black_dead; }
