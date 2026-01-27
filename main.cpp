#include <iostream>

#include "Game.h"
#include "Renderer.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {

    //Gets paths of piecetextures
    std::array<const char*, 12> pieces = {
        "C:/Users/ranhe/CLionProjects/Chess/pieces-basic-png/white-pawn.png",
        "C:/Users/ranhe/CLionProjects/Chess/pieces-basic-png/white-rook.png",
        "C:/Users/ranhe/CLionProjects/Chess/pieces-basic-png/white-knight.png",
        "C:/Users/ranhe/CLionProjects/Chess/pieces-basic-png/white-bishop.png",
        "C:/Users/ranhe/CLionProjects/Chess/pieces-basic-png/white-queen.png",
        "C:/Users/ranhe/CLionProjects/Chess/pieces-basic-png/white-king.png",
        "C:/Users/ranhe/CLionProjects/Chess/pieces-basic-png/black-pawn.png",
        "C:/Users/ranhe/CLionProjects/Chess/pieces-basic-png/black-rook.png",
        "C:/Users/ranhe/CLionProjects/Chess/pieces-basic-png/black-knight.png",
        "C:/Users/ranhe/CLionProjects/Chess/pieces-basic-png/black-bishop.png",
        "C:/Users/ranhe/CLionProjects/Chess/pieces-basic-png/black-queen.png",
        "C:/Users/ranhe/CLionProjects/Chess/pieces-basic-png/black-king.png"
    };

    //loads textures to an array
    std::array<sf::Texture, 12> pieceTextures;
    for (int i = 0; i < 12; ++i) {
        if (!pieceTextures[i].loadFromFile(pieces[i])) {
            throw std::runtime_error("failed to load texture from char");
        }
    }

    Game game;
    Renderer renderer(pieceTextures);



    std::cout << "Generated moves:\n";
    game.generateLegalMoves();
    std::cout << "Done\n";

    while (renderer.isOpen()) {

        renderer.render(game);
    }

    return 0;
}