//
// Created by ranhe on 30.12.2025.
//

#include "Board.h"


Board::Board() {

    //Clears board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = PieceType::NoPiece;
        }
    }

    //Places white pawns
    for (int i = 0 ; i < 8; i++) {
        board[6][i] = PieceType::W_Pawn;
    }

    //Places black pawns
    for (int i = 0 ; i < 8; i++) {
        board[1][i] = PieceType::B_Pawn;
    }

    //Places rest of pieces
    board[7][0] = PieceType::W_Rook;
    board[7][1] = PieceType::W_Knight;
    board[7][2] = PieceType::W_Bishop;
    board[7][3] = PieceType::W_Queen;
    board[7][4] = PieceType::W_King;
    board[7][5] = PieceType::W_Bishop;
    board[7][6] = PieceType::W_Knight;
    board[7][7] = PieceType::W_Rook;

    board[0][0] = PieceType::B_Rook;
    board[0][1] = PieceType::B_Knight;
    board[0][2] = PieceType::B_Bishop;
    board[0][3] = PieceType::B_Queen;
    board[0][4] = PieceType::B_King;
    board[0][5] = PieceType::B_Knight;
    board[0][6] = PieceType::B_Bishop;
    board[0][7] = PieceType::B_Rook;
}

const PieceType (&Board::getBoard())[8][8] {
    return board;
}

void Board::updatePieces(int startX, int startY, int endX, int endY) {
    PieceType piece = board[startX][startY];
    board[startX][startY] = PieceType::NoPiece;
    board[endX][endY] = piece;
}

bool Board::hasPiece(int x, int y) const{
    return board[x][y] != PieceType::NoPiece;
}

PieceType Board::getPiece(int x, int y) const{
    PieceType piece = board[x][y];
    return piece;
}

bool isWhite(PieceType piece) {
    if (piece == PieceType::W_Pawn || piece == PieceType::W_Bishop || piece == PieceType::W_Knight || piece == PieceType::W_Rook || piece == PieceType::W_King || piece == PieceType::W_Queen) {
        return true;
    }
    return false;
}

void Board::movePiece(int startX, int startY, int endX, int endY) {
    PieceType piece = getPiece(startX, startY);
    board[startX][startY] = PieceType::NoPiece;
    board[endX][endY] = piece;
}

