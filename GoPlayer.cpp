#include <iostream>
#include <string>

#include "Coordinate.h"
#include "GoGameState.h"

Coordinate GoPlayer::NextAction(GoGameState state) {
   int x,y;
   cin >> x;
   cin >> y;
   x--;
   y--;
   Coordinate c(x,y);
   return c;
}
