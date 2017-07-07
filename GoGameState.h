#ifndef GO_GAMESTATE_H
#define GOBOARD_H

enum class CellState{EMPTY, BLACK, WHITE};

struct GoGameState {
	//board
   int size;
   vector<vector<CellState>> grid;

   //captured stones
   int white_dead; //number of white stones captured
   int black_dead; //number of black stones captured

   //constructor
   GoGameState(int size);

   //helper functions
   void setCell(int x, int y, CellState cs);
   CellState getCell(int x, int y);
   
   void kill_white();
   void kill_black();
   int  get_white_dead();
   int get_black_dead();

};


#endif /* GO_GAMESTATE_H */
