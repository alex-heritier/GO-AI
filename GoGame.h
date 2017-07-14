#ifndef GOGAMEENGINE_H
#define GOGAMEENGINE_H

#include "GoGameState.h"
#include "GoPlayer.h"

class GoGame {
   GoGameState board;
   int turn_num;

   //constructor
   GoGame(GoPlayer black, GoPlayer white);

   //
}


#endif /* GOGAMEENGINE_H */
