#include <iostream>
#include <string>

#include "GoGame.h"
#include "Coordinate.h"

GoGame::GoGame(int size, GoPlayer _black, GoPlayer _white):
   state(size),
   turn(0),
   black(_black),
   white(_white)
   {}

void GoGame::PlayGame(bool display) {
   Coordinate nextMove;
   while(true) {
      //black plays
      nextMove = black.NextAction(state);
      //LogMove(nextMove)
      PlayMove(nextMove, PlayerColor::BLACK);

      //debug display
      if(display)
         printGoState(state);

      //white plays
      //LogMove(nextMove)
      PlayMove(nextMove, PlayerColor::BLACK);

      //debug display
      if(display)
         printGoState(state);
   }
}

//to be made more intricate later
void GoGame::PlayMove(Coordinate nextMove, PlayerColor color) {
   if(color = PlayerColor::BLACK)
      state.setCell(nextMove, CellState::BLACK);
   if(color = PlayerColor::WHITE)
      state.setCell(nextMove, CellState::WHITE);
}

//debug display functions ----------------------------------------------
string shortHand(CellState cs) {
   if(cs == CellState::BLACK) return "B";
   if(cs == CellState::WHITE) return "W";
   return "+";
}
void printGoState(GoGameState gs) {
   string output;
   for(int y = gs.size-1; y >= 0; y--) {
      for(int x = 0; x < gs.size; x++) {
         Coordinate c(x,y);
         CellState cs = gs.getCell(c);
         output = shortHand(cs);
         if(output == "+" && isStarCoord(c)) {
            output = "x";
         }
         cout << output << " ";
      }
      cout << "\n";
   }
   cout << "white dead: " << gs.getWhiteDead() << " | ";
   cout << "black dead: " << gs.getBlackDead() << "\n";
}
