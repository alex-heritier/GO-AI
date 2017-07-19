#ifndef GO_GAMESTATE_H
#define GO_GAMESTATE_H

#include <vector>

#include "Coordinate.h"

enum class CellState {EMPTY, BLACK, WHITE};
enum class PlayerColor {BLACK, WHITE};
CellState playerColorToCellState(PlayerColor color);

struct GoGameState {
public:
    // Data
    const int size; // represents vertices, NOT cells
    int white_dead; // number of white stones captured
    int black_dead; // number of black stones captured
    mutable int turn;
    mutable bool activePlayer = true;

    // Methods
    GoGameState(int size);
    int getWhiteDead() const;
    int getBlackDead() const;
    int endTurn();
    CellState setCell(const Coordinate&, const CellState);
    CellState getCell(const Coordinate&) const;
private:
	// Data
   std::vector<std::vector<CellState> > grid;

   // Methods
   void killWhite();
   void killBlack();
   int getTurn() const;
};

#endif /* GO_GAMESTATE_H */
