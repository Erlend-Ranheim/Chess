#include <iostream>

#include "Game.h"
#include "Renderer.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {

    Game game;


    sf::Texture chessboardTexture;
    if (!chessboardTexture.loadFromFile(
        "C:/Users/ranhe/CLionProjects/Chess/Chess_Board.png"))
    {
        std::cerr << "Failed to load image\n";
        return 1;
    }

    Renderer renderer(chessboardTexture);

    while (renderer.isOpen()) {
        renderer.render();
    }

    return 0;
}