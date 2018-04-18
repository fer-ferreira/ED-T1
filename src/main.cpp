#include "Config.hpp"
#include "Game.hpp"

#include <iostream>
#define SFML_STATIC

int main() {
    Game game( TITLE, WINDOW_HEIGHT, WINDOW_WIDTH, FRAME_LIMIT );
    game.run();
    return 0;
}
