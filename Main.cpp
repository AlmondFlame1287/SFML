#include "Game.h"

int main() {

    Game game;

    while(game.isWindowOpen()) {
        // Update 
        game.update();


        // Render
        game.render();
    }
    
    return 0;
}