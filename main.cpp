#include <iostream>
#include <SDL.h>
#include "Game.h"

int main() {
    Game Snake;
    if (Snake.game() && Snake.loadMedia()) {
            Snake.run();
        }
        Snake.close();
    }
    return 0;
}
