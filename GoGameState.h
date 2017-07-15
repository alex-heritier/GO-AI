#ifndef GO_GAMESTATE_H
#define GO_GAMESTATE_H

#include <vector>

#include "Coordinate.h"

enum class CellState{EMPTY, BLACK, WHITE};

struct GoGameState {
	//board
   int size;
   std::vector<std::vector<CellState> > grid;

   //captured stones
   int white_dead; //number of white stones captured
   int black_dead; //number of black stones captured

   // last clicked pixel
   mutable Coordinate clickedPixel;

   //constructor
   GoGameState(int);

   //helper functions
   CellState setCell(const Coordinate&, const CellState);
   CellState getCell(const Coordinate&) const;

   void killWhite();
   void killBlack();
   int getWhiteDead() const;
   int getBlackDead() const;
};

#endif /* GO_GAMESTATE_H */
