//
// Created by ranhe on 30.12.2025.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include "Board.h"
#include "Move.h"
#include <vector>

class Game {
    Board board;

    void generateKingMoves(int r, int c, std::vector<Move>& legalMoves) const;

    void generateQueenMoves(int r, int c, std::vector<Move>& legalMoves) const;

    void generateRookMoves(int r, int c, std::vector<Move>& legalMoves) const;

    void generateBishopMoves(int r, int c, std::vector<Move>& legalMoves) const;

    void generateKnightMoves(int r, int c, std::vector<Move>& legalMoves) const;

    void generatePawnMoves(int r, int c, std::vector<Move>& legalMoves) const;

    public:
        Game();
        std::vector<Move> generateLegalMoves() const;


};

#endif //CHESS_GAME_H