#include <iostream>
#include <string>

#include "Coordinate.h"
#include "GoGameState.h"
#include "GoPlayer.h"

using namespace std;

GoPlayer::GoPlayer(PlayerColor _color): color(_color) {}

GoPlayer::~GoPlayer() {}

//this class should be extened
//the default functions return junk
Coordinate GoPlayer::NextAction(GoGameState state) {
   Coordinate c(1,1);
   return c;
}
