//
// Created by ranhe on 30.12.2025.
//

#include "Game.h"

#include <iostream>

Game::Game() {
}


void Game::updateBoard(const Move& move) {
    board.updatePieces(move.startRow, move.startCol, move.endRow, move.endCol);
}

static bool inBounds(int r, int c) {
    return r >= 0 && r < 8 && c >= 0 && c < 8;
}

static bool isWhite(PieceType p) {
    return p == PieceType::W_Pawn || p == PieceType::W_Rook || p == PieceType::W_Knight ||
           p == PieceType::W_Bishop || p == PieceType::W_Queen || p == PieceType::W_King;
}

static void printMoveList(const std::vector<Move>& moves) {
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
                    generateKingMoves(r,c,legalMoves, true);
                    break;
                case PieceType::B_King:
                    generateKingMoves(r,c,legalMoves, false);
                    break;

                case PieceType::W_Queen:
                    generateQueenMoves(r,c,legalMoves, true);
                    break;
                case PieceType::B_Queen:
                    generateQueenMoves(r,c,legalMoves, false);
                    break;

                case PieceType::W_Bishop:
                    generateBishopMoves(r,c,legalMoves, true);
                    break;
                case PieceType::B_Bishop:
                    generateBishopMoves(r,c,legalMoves, false);
                    break;

                case PieceType::W_Knight:
                    generateKnightMoves(r,c,legalMoves, true);
                    break;
                case PieceType::B_Knight:
                    generateKnightMoves(r,c,legalMoves, false);
                    break;

                case PieceType::W_Rook:
                    generateRookMoves(r,c,legalMoves, true);
                    break;
                case PieceType::B_Rook:
                    generateRookMoves(r,c,legalMoves, false);
                    break;

                case PieceType::W_Pawn:
                    generatePawnMoves(r,c,legalMoves, true);
                    break;
                case PieceType::B_Pawn:
                    generatePawnMoves(r,c,legalMoves, false);
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


void Game::generateKingMoves(int r, int c, std::vector<Move>& legalMoves, bool isWhite) const {
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {

            //We skip the square the king is on
            if (dr == 0 && dc == 0) continue;

            //The alternative squares
            int rr = r + dr;
            int cc = c + dc;

            if (!inBounds(rr,cc)) continue;

            PieceType target = board.getPiece(rr,cc);
            if (target == PieceType::NoPiece || isWhite != ::isWhite(target)) {
                legalMoves.push_back(Move(r,c,rr,cc));
            }

        }
    }
}

void Game::generateQueenMoves(int r, int c, std::vector<Move>& legalMoves, bool isWhite) const {
    const int dirs[8][2] = {
        {1,0},{-1,0}, {0,1}, {0,-1}, //Horizontal & verticals
        {1,1}, {1,-1}, {-1,1}, {-1,-1} //Diagonals
    };

    for (auto& dir : dirs) {
        int rr = r + dir[0];
        int cc = c + dir[1];

        while (inBounds(rr,cc)) {
            PieceType target = board.getPiece(rr,cc);

            if (target == PieceType::NoPiece) {
                legalMoves.push_back(Move(r,c,rr,cc));
            }else {
                if (isWhite != ::isWhite(target)) {
                    legalMoves.push_back(Move(r,c,rr,cc));
                }
                break;
            }
            rr += dir[0];
            cc += dir[1];
        }
    }
}

void Game::generateRookMoves(int r, int c, std::vector<Move>& legalMoves, bool isWhite) const {
    const int dirs[4][2] = {
        {1,0},{-1,0}, {0,1}, {0,-1} //Horizontal & verticals
    };

    for (auto& dir : dirs) {
        int rr = r + dir[0];
        int cc = c + dir[1];

        while (inBounds(rr,cc)) {
            PieceType target = board.getPiece(rr,cc);
            if (target == PieceType::NoPiece) {
                legalMoves.push_back(Move(r,c,rr,cc));
            }else {
                if (isWhite != ::isWhite(target)) {
                    legalMoves.push_back(Move(r,c,rr,cc));
                }
                break;
            }
            rr += dir[0];
            cc += dir[1];
        }
    }
}

void Game::generateBishopMoves(int r, int c, std::vector<Move>& legalMoves, bool isWhite) const {
    const int dirs[4][2] = {
        {1,1}, {1,-1}, {-1,1}, {-1,-1} //Horizontal & verticals
    };

    for (auto& dir : dirs) {
        int rr = r + dir[0];
        int cc = c + dir[1];

        while (inBounds(rr,cc)) {
            PieceType target = board.getPiece(rr,cc);
            if (target == PieceType::NoPiece) {
                legalMoves.push_back(Move(r,c,rr,cc));
            }else {
                if (isWhite != ::isWhite(target)) {
                    legalMoves.push_back(Move(r,c,rr,cc));
                }
                break;
            }
            rr += dir[0];
            cc += dir[1];
        }
    }
}

void Game::generateKnightMoves(int r, int c, std::vector<Move>& legalMoves, bool isWhite) const {

    const int dirs[8][2] = {
        {-2, -1}, {-2,  1},
        {-1, -2}, {-1,  2},
        { 1, -2}, { 1,  2},
        { 2, -1}, { 2,  1}
    };

    for (auto& dir : dirs) {
        int rr = r + dir[0];
        int cc = c + dir[1];

        if (inBounds(rr,cc)) {
            PieceType target = board.getPiece(rr,cc);

            if (target == PieceType::NoPiece || isWhite != ::isWhite(target)) {
                legalMoves.push_back(Move(r,c,rr,cc));
            }
        }
    }
}

void Game::generatePawnMoves(int r, int c, std::vector<Move>& legalMoves, bool isWhite) const {

    const int dir = isWhite ? -1 : +1;
    const int startRow = isWhite ? 6 : 1;

    int r1 = r + dir;

    //Single move forwards
    if (inBounds(r1,c) && board.getPiece(r1,c) == PieceType::NoPiece) {
        legalMoves.push_back(Move(r,c,r1,c));
    }

    //Double move
    int r2 = r + 2*dir;
    if (r == startRow && board.getPiece(r2,c) == PieceType::NoPiece) {
        legalMoves.push_back(Move(r,c,r2,c));
    }

    //diagonal capture
    for (int dc : {-1,1}) {
        int cc = c + dc;
        if (inBounds(r1,cc)) {
            PieceType target = board.getPiece(r1,cc);
            if (target != PieceType::NoPiece && isWhite != ::isWhite(target)) {
                legalMoves.push_back(Move(r,c,r1,cc));
            }
        }
    }

}
