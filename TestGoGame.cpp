
#include <iostream>

#include "GoGame.h"
#include "GoGameState.h"
#include "GoPlayerHuman.h"
#include "GoPlayer.h"
#include "GoView.h"

using namespace std;

int main() {
   //Start new game
   GoPlayerHuman black(PlayerColor::BLACK);
   GoPlayerHuman white(PlayerColor::WHITE);

   GoGameState gs(19);
   gs.grid[2][4] = CellState::BLACK;
   gs.grid[4][2] = CellState::WHITE;
   gs.grid[12][9] = CellState::BLACK;
   gs.grid[1][18] = CellState::WHITE;
   gs.grid[7][7] = CellState::BLACK;
   gs.grid[15][12] = CellState::WHITE;

   GoGame game(19, black, white);

   //play game
   game.PlayGame(true);

   //GoView view(gs, "Go AI", 1000, 600);
   //view.run();

   return 0;
}
