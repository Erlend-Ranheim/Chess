//
// Created by ranhe on 30.12.2025.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

enum class PieceType : int {
    W_King,
    W_Bishop,
    W_Knight,
    W_Queen,
    W_Rook,
    W_Pawn,

    B_King,
    B_Bishop,
    B_Knight,
    B_Queen,
    B_Rook,
    B_Pawn,

    NoPiece
};

class Board {
    PieceType board[8][8];

    public:

        const PieceType (&getBoard())[8][8];
        bool hasPiece(int x, int y) const;
        PieceType getPiece(int x, int y) const;
        void movePiece(int startX, int startY, int endX, int endY);
        Board();
};


#endif //CHESS_BOARD_H