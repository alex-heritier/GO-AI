#include <iostream>
#include <string>

#include "GoGame.h"
#include "Coordinate.h"

using namespace std;

GoGame::GoGame(int size, GoPlayer &_black, GoPlayer &_white):
   state(size),
   black(_black),
   white(_white)
   {}

//playes whole game
void GoGame::PlayGame(bool display) {
   Coordinate nextMove(1,1);

   //debug display
   if(display)
      printGoState(state);

   while(true) {

      //black plays
      nextMove = black.NextAction(state);
      while( !PlayMove(nextMove, PlayerColor::BLACK) ) {
         cout << "An illegal move was played!";
         nextMove = black.NextAction(state);
         //LogMove(nextMove) //TODO
      }

      //debug display
      if(display) printGoState(state);

      //white plays
      nextMove = white.NextAction(state);
      while( !PlayMove(nextMove, PlayerColor::WHITE) ) {
         cout << "An illegal move was played!";
         nextMove = white.NextAction(state);
         //LogMove(nextMove) //TODO
      }

      //debug display
      if(display) printGoState(state);
   }
}

//functions which enforce go rules ------------------------------------

//updates gamestate and returns true if move is legal
//else returns false
bool GoGame::PlayMove(Coordinate nextMove, PlayerColor color) {
   int isLegalMove = true;

   //check if coordinate already occupied

   //temporarily place stone ub in coordinate

   //capture enemy stones if possible

   //check if in a captured state,
   //if so remove stone and return false



   if(color == PlayerColor::BLACK)
      state.setCell(nextMove, CellState::BLACK);
   if(color == PlayerColor::WHITE)
      state.setCell(nextMove, CellState::WHITE);

   if(isLegalMove) state.endTurn();
   return isLegalMove;
}

//debug display functions ----------------------------------------------
string shortHand(CellState cs) {
   if(cs == CellState::BLACK) return "B";
   if(cs == CellState::WHITE) return "W";
   return "+";
}
bool isStarCoord(Coordinate c) {
   int x = c.getX();
   int y = c.getY();
   bool val = x == 3 || x == 9 || x == 15;
   val = val && (y == 3 || y == 9 || y == 15);
   return val;
}
void GoGame::printGoState(GoGameState gs) {
   string output;
   for(int y = gs.size-1; y >= 0; y--) {
      for(int x = 0; x < gs.size; x++) {
         Coordinate c(x,y);
         CellState cs = gs.getCell(c);
         output = shortHand(cs);
         if(output == "+" && isStarCoord(c) && gs.size == 19) {
            output = "x";
         }
         cout << output << " ";
      }
      cout << "\n";
   }
   cout << "white dead: " << gs.getWhiteDead() << " | ";
   cout << "black dead: " << gs.getBlackDead() << " | ";
   gs.turn%2 == 0? cout << "black " : cout << "white ";
   cout << "to play \n";
}
