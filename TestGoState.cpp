
#include <iostream>

#include "GoGameState.h"
#include "GoView.h"

using namespace std;

string shortHand(CellState cs) {
    if (cs == CellState::BLACK) return "*";
    if (cs == CellState::WHITE) return "o";
    return "+";
}

void printGoState(GoGameState gs) {
    for (int y = gs.size - 1; y >= 0; y--) {
        for (int x = 0; x < gs.size; x++) {
            Coordinate c(x,y);

            CellState cs = gs.getCell(Coordinate(x, y));
            cout << shortHand(cs) << " ";
        }
        cout << "\n";
    }
}

int main() {
    //build a gamestate
    GoGameState gs(19);

    cout<< "flag1" << endl;
    //print gamestate
    printGoState(gs);

    GoView view(gs, string("GO AI"), 1000, 600);
    view.run();

    return 0;
}
