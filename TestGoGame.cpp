
#include <iostream>

#include "GoGame.h"
#include "GoGameState.h"
#include "GoPlayerHuman.h"

using namespace std;

int main() {
   //Start new game
   GoPlayerHuman black(PlayerColor::BLACK);
   GoPlayerHuman white(PlayerColor::WHITE);

   GoGame game(19, black, white);

   //play game
   game.PlayGame(true);

   return 0;
}
