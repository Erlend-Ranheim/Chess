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

    //Finds values for size of entire window, and the size of the board which is 80% of the window
    float windowSize = std::min(window.getSize().y, window.getSize().x);
    boardSize = windowSize * 0.8f;

    //Origin is the amount we have to shift the pieces by when rendering. Its the same value as the width of the border on either side.
    // Tile is the size of a single square
    origin = {(window.getSize().x - boardSize) / 2.f, (window.getSize().y - boardSize) / 2.f};
    tile = boardSize / 8.0f;


    //Declares a single tile, and the two color it will be set to
    sf::RectangleShape square({tile,tile});
    sf::Color colorRed = {173, 106, 108};
    sf::Color colorWhite = {240,240,240};

    //Here a square is set based on the origin offset, and every other is colored
    //We draw each tile and move on to the next one
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            square.setPosition({origin.x + c * tile, origin.y + r * tile});
            (r+c) % 2 == 0 ? square.setFillColor(colorWhite) : square.setFillColor(colorRed);
            window.draw(square);
        }
    }

    //Higlights selected square(If a square is selected)
    if (hasSelection) {
        sf::RectangleShape square({tile,tile});
        sf::Color colorHighlight = {155,155,255, 50};
        square.setPosition({origin.x + selectedCol*tile, origin.y + selectedRow*tile});
        square.setFillColor(colorHighlight);
        window.draw(square);
    }
}


//Each piece is drawn with the offset "origin"
void Renderer::drawPiece(const sf::Texture& piece, int r, int c) {
    sf::Sprite pieceSprite(piece);
    pieceSprite.setPosition({origin.x + c * tile, origin.y + r * tile});

    sf::Vector2u ts = piece.getSize();
    float sx = tile / static_cast<float>(ts.x);
    float sy = tile / static_cast<float>(ts.y);
    pieceSprite.setScale({sx, sy});

    window.draw(pieceSprite);
}

//Helper function to find right coordinates of the board when having an offset
bool Renderer::mouseToBoard(int mx, int my, int& r, int& c) {
    if (mx < origin.x || my < origin.y) return false;
    if (mx >= (origin.x + boardSize) || my >= (origin.y + boardSize)) return false;

    //Finds which of the 8 squares you have clicked
    c = (mx - origin.x) / tile;
    r = (my - origin.y) / tile;
    return true;
}


void Renderer::render(Game& game) {
    // Process events
    while (const std::optional event = window.pollEvent())
    {
        // Close window: exit
        if (event->is<sf::Event::Closed>())
            window.close();

        //Resize window
        if (const auto* r = event -> getIf<sf::Event::Resized>()) {
            window.setView(sf::View(sf::FloatRect({0.f, 0.f},
                                                 {static_cast<float>(r->size.x), static_cast<float>(r->size.y)})));
        }

        //Logic to move pieces using the gui
        if (const auto* click = event -> getIf<sf::Event::MouseButtonPressed>()) {
            //Gets piece from click
            if (click->button == sf::Mouse::Button::Left) {
                int r,c;
                //1. collect coordinates from clicked square.
                if (mouseToBoard(click->position.x, click->position.y, r, c)) {
                    //Checks if this is the first or second square we click
                    //If clause goes through logic for first board selection, else clause goes through logic for second board selection
                    if (!hasSelection) {
                        if (game.getBoard().hasPiece(r,c)) {
                            hasSelection = true;
                            selectedCol = c;
                            selectedRow = r;
                            currentMoves.clear();

                            std::vector<Move> legalMoves = game.generateLegalMoves();

                            //Sorts throug every legal move and copies every item where start is the same as out clicked square
                            for (Move m : legalMoves) {
                                if (m.startCol == c && m.startRow == r) {
                                    currentMoves.push_back(m);
                                }
                            }
                        }

                    }else {
                        //Sorts through every move that the selected piece is able to do
                        for (Move m : currentMoves) {
                            //Checks if selected square is available for move
                            if (m.endCol == c && m.endRow == r) {
                                game.updateBoard(m);
                                break;
                            }
                        }

                        hasSelection = false;
                        currentMoves.clear();
                    }
                }
            }

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

