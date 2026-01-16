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
        void render(const Game& game);
        bool isOpen() const;

    private:
        float tile;
        sf::Vector2f origin;


        sf::RenderWindow window;
        sf::Sprite sprite;
        std::array<sf::Texture, 12>& pieceTextures;

        void drawPiece(const sf::Texture&, int r, int c);
        void drawBoard();
};


#endif //CHESS_RENDERER_H