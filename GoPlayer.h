#ifndef __GO_PLAYER_H__
#define __GO_PLAYER_H__

#include <iostream>
#include <string>

#include "Coordinate.h"
#include "GoGameState.h"

class GoPlayer {
public:
   Coordinate NextAction(GoGameState state);
};

#endif
