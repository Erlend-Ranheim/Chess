//
// Created by ranhe on 30.12.2025.
//

#include "Game.h"

#include <iostream>

Game::Game() {

}


static bool inBounds(int r, int c) {
    return r >= 0 && r < 8 && c >= 0 && c < 8;
}

static bool isWhite(PieceType p) {
    return p == PieceType::W_Pawn || p == PieceType::W_Rook || p == PieceType::W_Knight ||
           p == PieceType::W_Bishop || p == PieceType::W_Queen || p == PieceType::W_King;
}

static void printMoveList(std::vector<Move>& moves) {
    for (Move m : moves) {
        std::cout << "(" << m.startRow << "," << m.startCol << ") -> "
                  << "(" << m.endRow   << "," << m.endCol   << ")\n";
    }
}


//goes thorugh every square in position and calls the right function to generate the possible move for that square
std::vector<Move> Game::generateLegalMoves() const {

    std::vector<Move> legalMoves;

    for (int r = 0; r < 8; r++ ) {
        for (int c = 0; c < 8; c++ ) {
            PieceType piece = board.getPiece(r, c);
            switch (piece) {
                case PieceType::W_King:
                case PieceType::B_King:
                    generateKingMoves(r,c,legalMoves);
                    break;

                case PieceType::W_Queen:
                case PieceType::B_Queen:
                    generateQueenMoves(r,c,legalMoves);
                    break;

                case PieceType::W_Bishop:
                case PieceType::B_Bishop:
                    generateBishopMoves(r,c,legalMoves);
                    break;

                case PieceType::W_Knight:
                case PieceType::B_Knight:
                    generateKnightMoves(r,c,legalMoves);
                    break;

                case PieceType::W_Rook:
                case PieceType::B_Rook:
                    generateRookMoves(r,c,legalMoves);
                    break;

                case PieceType::W_Pawn:
                case PieceType::B_Pawn:
                    generatePawnMoves(r,c,legalMoves);
                    break;

                case(PieceType::NoPiece):
                default:
                    break;


            }
        }

    }

    printMoveList(legalMoves);
    return legalMoves;

}


void Game::generateKingMoves(int r, int c, std::vector<Move>& legalMoves) const {

}

void Game::generateQueenMoves(int r, int c, std::vector<Move>& legalMoves) const{}

void Game::generateRookMoves(int r, int c, std::vector<Move>& legalMoves) const{}

void Game::generateBishopMoves(int r, int c, std::vector<Move>& legalMoves) const{}

void Game::generateKnightMoves(int r, int c, std::vector<Move>& legalMoves) const{}

void Game::generatePawnMoves(int r, int c, std::vector<Move>& legalMoves) const {
    PieceType pawn = board.getPiece(r,c);

    bool White = isWhite(pawn);

    const int dir = White ? +1 : -1;

    const int startRow = White ? 1 : 6;


    int r1 = r + dir;

    //Move forwards
    if (inBounds(r1,c) && board.getPiece(r1,c) == PieceType::NoPiece) {
        legalMoves.push_back(Move(r,c,r1,c));
    }

}
