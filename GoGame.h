#ifndef GOGAMEENGINE_H
#define GOGAMEENGINE_H

#include "GoGameState.h"
#include "GoPlayer.h"

class GoGame {
   //game info
   GoGameState board;
   vector<Coordinate> history;
   int turn;
   //players
   GoPlayer black;
   GoPlayer white;

   //constructor
   GoGame(GoPlayer black, GoPlayer white);

   //play game
   void PlayGame();

   //helper functions
   
}


#endif /* GOGAMEENGINE_H */
