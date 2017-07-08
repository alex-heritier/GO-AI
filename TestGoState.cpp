#include <stdlib>
#include <stdio>
#include "GoGameState.h"

using namespace std;

string shortHand(CellState cs) {
     if(cs == CellState.BLACK) return "b";
     if(cs == CellState.WHITE) return "w";
     return "-";
}

void printGoState(GoGameState gs) {
     for(int y = gs.size; y > 0; y++) {
           for(int x = 0; x < gs.size; x++) {
                Coordinate c = new Coordinate(x,y);
                CellState cs = gs.getCell(c);
                cout << shortHand(cs);
           }
           cout << "\n";
     }
}

int main() {
     //build a gamestate
     gs = new GoGameState(19);
     
     //print gamestate
     printGoState(gs);

     return 0;
}
