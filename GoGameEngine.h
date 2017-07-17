#ifndef GOGAMEENGINE_H
#define GOGAMEENGINE_H

#include "GoGameState.h"
#include "GoPlayer.h"
#include "Coordinate.h"

using namespace std;

class GoGame {
public:
   //game info
   GoGameState state;

   //players
   GoPlayer &black;
   GoPlayer &white;

   //constructor
   GoGame(int size, GoPlayer &black, GoPlayer &white);

   //play game
   void PlayGame(bool display = false);

   //TODO: play turn (so AI can do readahead)

private:
   bool PlayMove(Coordinate nextMove, PlayerColor color);
   void printGoState(GoGameState gs);

   //capturing functions

   //capture_from_move()
   //input : Coordinate and player color of a move
   //effect: remove from board all stones captured due to
   //        a given move and increment the captured stone
   //        counters
   void captureFromMove(Coordinate move, PlayerColor color);
   //get_capture_list()
   //input : - coordinate of stone that may need to be captured
   //        - coordinates of stones in the same group as input
   //          stone that have already been checked.
   //output: list of all stones that definitely need to be captured
   Coordinates getCaptured(Coordinate candidate, Coordinates checked);

   //helper functions

   //debug display functions

};


#endif /* GOGAMEENGINE_H */
