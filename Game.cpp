//
// Created by ranhe on 30.12.2025.
//

#include "Game.h"

Game::Game() {


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

    return legalMoves;

}


void Game::generateKingMoves(int r, int c, std::vector<Move>& legalMoves) const {}

void Game::generateQueenMoves(int r, int c, std::vector<Move>& legalMoves) const{}

void Game::generateRookMoves(int r, int c, std::vector<Move>& legalMoves) const{}

void Game::generateBishopMoves(int r, int c, std::vector<Move>& legalMoves) const{}

void Game::generateKnightMoves(int r, int c, std::vector<Move>& legalMoves) const{}

void Game::generatePawnMoves(int r, int c, std::vector<Move>& legalMoves) const{}
