//
// Created by ranhe on 10.01.2026.
//

#ifndef CHESS_RENDERER_H
#define CHESS_RENDERER_H
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "Board.h"


class Renderer {
    public:
        Renderer(std::array<sf::Texture, 12>& pieces);
        void render(Game& game);
        bool isOpen() const;
        PieceType selectPiece() const;

    private:
        float boardSize;
        float tile;
        sf::Vector2f origin;

        bool hasSelection = false;
        int selectedRow = -1;
        int selectedCol = -1;
        std::vector<Move> currentMoves;

        sf::RenderWindow window;
        sf::Sprite sprite;
        std::array<sf::Texture, 12>& pieceTextures;

        bool mouseToBoard(int mx, int my, int& r, int& c);
        void drawPiece(const sf::Texture&, int r, int c);
        void drawBoard();

};


#endif //CHESS_RENDERER_H