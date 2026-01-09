//
// Created by ranhe on 30.12.2025.
//

#include "Game.h"

    //goes thorugh every square in position and calls the right function to generate the possible move for that square
    std::vector<Move> Game::generateLegalMoves() {


        for (int r = 0; r < 8; r++ ) {
            for (int c = 0; c < 8; c++ ) {

                switch (PieceType piece = board.getPiece(r, c)) {
                    case PieceType::W_King:
                    case PieceType::B_King:
                        generateKingMoves();
                        break;

                    case PieceType::W_Queen:
                    case PieceType::B_Queen:
                        generateQueenMoves();
                        break;

                    case PieceType::W_Bishop:
                    case PieceType::B_Bishop:
                        generateBishopMoves();
                        break;

                    case PieceType::W_Knight:
                    case PieceType::B_Knight:
                        generateKnightMoves();
                        break;

                    case PieceType::W_Rook:
                    case PieceType::B_Rook:
                        generateRookMoves();
                        break;

                    case PieceType::W_Pawn:
                    case PieceType::B_Pawn:
                        generatePawnMoves();
                        break;

                    case(PieceType::NoPiece):
                    default:
                        break;


                }
            }

    };

}
//Lookup in the generated list/vector if the given start and end positions exists, return true/false
//bool checkLegalMove(int startX, int startY, int endX, int endY) {
