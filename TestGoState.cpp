
#include <iostream>
#include "GoGameState.h"

using namespace std;

string shortHand(CellState cs) {
   if(cs == CellState::BLACK) return "B";
   if(cs == CellState::WHITE) return "W";
   return "+";
}

bool isStarCoord(Coordinate c) {
   int x = c.getX();
   int y = c.getY();
   bool val = x == 3 || x == 9 || x == 15;
   val = val && (y == 3 || y == 9 || y == 15);
   return val;
}

void printGoState(GoGameState gs) {
   string output;
   for(int y = gs.size-1; y >= 0; y--) {
      for(int x = 0; x < gs.size; x++) {
         Coordinate c(x,y);
         CellState cs = gs.getCell(c);
         output = shortHand(cs);
         if(output == "+" && isStarCoord(c)) {
            output = "x";
         }
         cout << output << " ";
      }
      cout << "\n";
   }
   cout << "white dead: " << gs.getWhiteDead() << " | ";
   cout << "black dead: " << gs.getBlackDead() << "\n";
}

int main() {
   //build a gamestate
   GoGameState gs(19);

   //print gamestate
   printGoState(gs);

   //play game
   int turn = 0;
   while(true) {
      int x,y;
      cin >> x;
      cin >> y;
      x--;
      y--;
      Coordinate c(x,y);
      if(turn%2 == 0)
         gs.setCell(c, CellState::BLACK);
      else
         gs.setCell(c, CellState::WHITE);

      printGoState(gs);
      turn++;
   }
   int i;
   cin >> i;
   cout << i;

   return 0;
}
