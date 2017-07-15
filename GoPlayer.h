#ifndef __GO_PLAYER_H__
#define __GO_PLAYER_H__

#include <iostream>
#include <string>

#include "Coordinate.h"
#include "GoGameState.h"

class GoPlayer {
protected:
   PlayerColor color;
public:
   GoPlayer(PlayerColor _color);
   virtual Coordinate NextAction(GoGameState state);
};

#endif
