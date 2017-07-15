#include <iostream>
#include <string>

#include "Coordinate.h"
#include "GoGameState.h"
#include "GoPlayer.h"

using namespace std;

Coordinate GoPlayer::NextAction(GoGameState state) {
   int x,y;
   cin >> x;
   cin >> y;
   x--;
   y--;
   Coordinate c(x,y);
   return c;
}
