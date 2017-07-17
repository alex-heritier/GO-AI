#include <iostream>
#include <string>

#include "GoGameEngine.h"
#include "GoGameState.h"
#include "Coordinate.h"

using namespace std;

GoGameEngine::GoGameEngine(GoGameState &state, GoPlayer &_black, GoPlayer &_white):
   state(state),
   black(_black),
   white(_white)
   {}

//playes whole game
void GoGameEngine::PlayGame(bool display) {
   Coordinate nextMove(1,1);

   //debug display
   if(display)
      printGoState(state);

   while(true) {

      //black plays
      nextMove = black.NextAction(state);
      while( !PlayMove(nextMove, PlayerColor::BLACK) ) {
         cout << "An illegal move was played!\n";
         nextMove = black.NextAction(state);
      }

      //debug display
      if(display) printGoState(state);

      //white plays
      nextMove = white.NextAction(state);
      while( !PlayMove(nextMove, PlayerColor::WHITE) ) {
         cout << "An illegal move was played!\n";
         nextMove = white.NextAction(state);
      }

      //debug display
      if(display) printGoState(state);
   }
}

//functions which enforce go rules ------------------------------------

//updates gamestate and returns true if move is legal
//else returns false
bool GoGameEngine::PlayMove(Coordinate nextMove, PlayerColor color) {
   int isLegalMove = true;

   //check if coordinate already occupied
   if(state.getCell(nextMove) != CellState::EMPTY)
      return false;
   //temporarily place stone on in coordinate
   state.setCell(nextMove, playerColorToCellState(color));

   //capture enemy stones if possible
   //captureFromMove(nextMove, color);

   //check if in a captured state,
   //if so remove stone and return false
   if(!isLegalMove)
      state.setCell(nextMove, CellState::EMPTY);

   if(isLegalMove) state.endTurn();
   return isLegalMove;
}

//capture_from_move()
//input : Coordinate and player color of a move
//effect: remove from board all stones captured due to
//        a given move and increment the captured stone
//        counters
/*void GoGameEngine::captureFromMove(Coordinate move, PlayerColor color) {
   //I don't think any of this is right...............

   //check each side of the stone
   Coordinates checked;
   Coordinates dChecked;
   Coordinates foes = getAdjacentEnemies(move, color); //adjacent enemies
   for(Coordinate foe:foes) {
      //only check current foe if it has not been checked
      newChecked = getCaptured(foe, checked);
      checked.insert(checked.end(), dChecked.begin(), dChecked.end())
   }
   return;
}*/
//get_capture_list()
//input : - coordinate of stone that may need to be captured
//        - coordinates of stones in the same group as input
//          stone that have already been checked.
//output: list of all stones that definitely need to be captured
/*Coordinates GoGameEngine::getCaptured(Coordinate candidate,
   Coordinates checked) {

   Coordinates temp;
   return temp;
}

Coordinates GoGameEngine::getAdjacentEnemies(Coordinate move,
   PlayerColor color) {

}*/

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
void GoGameEngine::printGoState(GoGameState gs) {
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
