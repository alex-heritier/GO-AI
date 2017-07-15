#ifndef GOGAMEENGINE_H
#define GOGAMEENGINE_H

#include "GoGameState.h"
#include "GoPlayer.h"
#include "Coordinate.h"

enum class PlayerColor{BLACK, WHITE};

class GoGame {
   //game info
   GoGameState state;
   vector<Coordinate> history;
   int turn;
   //players
   GoPlayer black;
   GoPlayer white;

   //constructor
   GoGame(int size, GoPlayer black, GoPlayer white);

   //play game
   void PlayGame(bool display = false);

   //helper functions

   //debug display functions


}


#endif /* GOGAMEENGINE_H */
