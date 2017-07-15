
#include <iostream>

#include "GoGame.h"
#include "GoPlayer.h"

using namespace std;

int main() {
   //Start new game
   GoPlayer black;
   GoPlayer white;

   GoGame game(19, black, white);

   //play game
   game.PlayGame(true);

   return 0;
}
