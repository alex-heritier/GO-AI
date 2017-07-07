#ifndef GO_GAMESTATE_H
#define GOBOARD_H

enum MicroState{EMPTY, BLACK, WHITE};

struct GoBoard {
   int size;
   vector<vector<MicroState>>;
};

struct GoStoneCaptures {
   int white_dead; //number of white stones captured
   int black_dead; //number of black stones captured
};

class GoGameState {
   //board state
   //stone state
};


#endif /* GO_GAMESTATE_H */
