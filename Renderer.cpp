//
// Created by ranhe on 10.01.2026.
//

#include "Renderer.h"

#include <iostream>
#include <SFML/Graphics.hpp>

Renderer::Renderer(std::array<sf::Texture, 12>& pieceTextures) : window(sf::VideoMode({800, 800}), "Chess"),
                                                                 sprite(pieceTextures[0]), pieceTextures(pieceTextures) {
}

void Renderer::drawBoard() {


    float windowSize = std::min(window.getSize().y, window.getSize().x);
    float boardSize = windowSize * 0.8f;

    origin = {(window.getSize().x - boardSize) / 2.f, (window.getSize().y - boardSize) / 2.f};
    tile = boardSize / 8.0f;


    sf::RectangleShape square({tile,tile});

    sf::Color colorRed = {173, 106, 108};
    sf::Color colorWhite = {240,240,240};

    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            square.setPosition({origin.x + c * tile, origin.y + r * tile});
            (r+c) % 2 == 0 ? square.setFillColor(colorWhite) : square.setFillColor(colorRed);
            window.draw(square);
            }
        }
    }

void Renderer::drawPiece(const sf::Texture& piece, int r, int c) {
    sf::Sprite pieceSprite(piece);
    pieceSprite.setPosition({origin.x + c * tile, origin.y + r * tile});

    sf::Vector2u ts = piece.getSize();
    float sx = tile / static_cast<float>(ts.x);
    float sy = tile / static_cast<float>(ts.y);
    pieceSprite.setScale({sx, sy});

    window.draw(pieceSprite);
}


void Renderer::render(const Game& game) {
    // Process events
    while (const std::optional event = window.pollEvent())
    {
        // Close window: exit
        if (event->is<sf::Event::Closed>())
            window.close();


        if (const auto* r = event -> getIf<sf::Event::Resized>()) {
            window.setView(sf::View(sf::FloatRect({0.f, 0.f},
                                                 {static_cast<float>(r->size.x), static_cast<float>(r->size.y)})));
        }
    }



    window.clear();

    const Board& board = game.getBoard();

    drawBoard();

    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            PieceType piece = board.getPiece(r,c);
            switch (piece) {
                case PieceType::W_King:
                    drawPiece(pieceTextures[5], r, c);
                    break;
                case PieceType::B_King:
                    drawPiece(pieceTextures[11], r, c);
                    break;

                case PieceType::W_Queen:
                    drawPiece(pieceTextures[4], r, c);
                    break;
                case PieceType::B_Queen:
                    drawPiece(pieceTextures[10], r, c);
                    break;

                case PieceType::W_Bishop:
                    drawPiece(pieceTextures[3], r, c);
                    break;
                case PieceType::B_Bishop:
                    drawPiece(pieceTextures[9], r, c);
                    break;

                case PieceType::W_Knight:
                    drawPiece(pieceTextures[2], r, c);
                    break;
                case PieceType::B_Knight:
                    drawPiece(pieceTextures[8], r, c);
                    break;

                case PieceType::W_Rook:
                    drawPiece(pieceTextures[1], r, c);
                    break;
                case PieceType::B_Rook:
                    drawPiece(pieceTextures[7], r, c);
                    break;

                case PieceType::W_Pawn:
                    drawPiece(pieceTextures[0], r, c);
                    break;
                case PieceType::B_Pawn:
                    drawPiece(pieceTextures[6], r, c);
                    break;
                case(PieceType::NoPiece):
                default:
                    break;
            }
        }
    }

    window.display();
}

bool Renderer::isOpen() const {
    return window.isOpen();
}

