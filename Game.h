//
// Created by ranhe on 30.12.2025.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include "Board.h"
#include "Move.h"
#include "vector"

class Game {

    Board board;

    public:
        Game();
        std::vector<Move> generateLegalMoves();
        bool checkLegalMove();

};

#endif //CHESS_GAME_H