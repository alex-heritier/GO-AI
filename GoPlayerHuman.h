#ifndef __GO_PLAYER_HUMAN_H__
#define __GO_PLAYER_HUMAN_H__

#include <iostream>
#include <string>

#include "Coordinate.h"
#include "GoGameState.h"

class GoPlayerHuman: public GoPlayer {
public:
   GoPlayerHuman(PlayerColor _color);
   Coordinate NextAction(GoGameState state);
};

#endif
