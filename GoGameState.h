#ifndef GO_GAMESTATE_H
#define GO_GAMESTATE_H

enum class CellState{EMPTY, BLACK, WHITE};

struct GoGameState {
	//board
   int size;
   vector<vector<CellState>> grid;

   //captured stones
   int white_dead; //number of white stones captured
   int black_dead; //number of black stones captured

   //constructor
   GoGameState(int);

   //helper functions
   void setCell(Coordinate, CellState);
   CellState getCell(Coordinate);

   void killCell(Coordinate);
   int  getWhiteDead();
   int getBlackDead();
};

#endif /* GO_GAMESTATE_H */
