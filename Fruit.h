//
// Created by Sandra Loja on 2024/11/2.
//

#ifndef SNAKEGAME_FRUIT_H
#define SNAKEGAME_FRUIT_H
#include <SDL.h>
#include "Game.h"
#include <random>

class Fruit : public Game {
public:
    struct Position{
        int x;
        int y;
    };
    Fruit(int x, int y);
    void getFruit_Position();
    void draw_fruit();
    friend class Game;
private:
    Position fruit_position;
    SDL_Color fruit_color;
};


#endif //SNAKEGAME_FRUIT_H
