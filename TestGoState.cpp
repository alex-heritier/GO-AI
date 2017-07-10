
#include <iostream>
#include "GoGameState.h"

using namespace std;

string shortHand(CellState cs) {
     if (cs == CellState::BLACK) return "*";
     if (cs == CellState::WHITE) return "o";
     return "+";
}

void printGoState(GoGameState gs) {
     for(int y = gs.size - 1; y >= 0; y--) {
           for(int x = 0; x < gs.size; x++) {
                Coordinate c(x,y);

                //cout << "x: " << x << ", y: " << y << endl;

                CellState cs = gs.getCell(Coordinate(x, y));
                //CellState cs = gs.getCell(c);
                //cout << shortHand(cs);
           }
           //cout << "\n";
     }
}

int main() {
     //build a gamestate
     GoGameState gs(19);

     cout<< "flag1" << endl;
     //print gamestate
     printGoState(gs);

     return 0;
}
