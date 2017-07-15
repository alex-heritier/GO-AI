#ifndef GOGAMEENGINE_H
#define GOGAMEENGINE_H

#include "GoGameState.h"
#include "GoPlayer.h"
#include "Coordinate.h"

using namespace std;

enum class PlayerColor{BLACK, WHITE};

class GoGame {
public:
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

private:
   void PlayMove(Coordinate nextMove, PlayerColor color);
   void printGoState(GoGameState gs);
   //helper functions

   //debug display functions

};


#endif /* GOGAMEENGINE_H */
