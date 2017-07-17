#include <iostream>
#include <string>

#include "Coordinate.h"
#include "GoGameState.h"
#include "GoPlayer.h"
#include "GoPlayerHuman.h"

using namespace std;

GoPlayerHuman::GoPlayerHuman(PlayerColor _color): GoPlayer(_color)  {}


Coordinate GoPlayerHuman::NextAction(GoGameState state) {
   int x,y;
   cout << "x? ";
   cin >> x;
   cout << "y? ";
   cin >> y;
   x--;
   y--;
   Coordinate c(x,y);
   return c;
}
