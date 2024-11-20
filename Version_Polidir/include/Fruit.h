//
// Created by Steven NIUBI on 2024/11/2.
//

#ifndef SNAKEGAME_FRUIT_H
#define SNAKEGAME_FRUIT_H
#include <SDL.h>
#include "Game.h"
#include <random>
class Game;
class Fruit {
public:
    struct Position{
        int x;
        int y;
    };
    Fruit(int x, int y);
    void getFruit_Position(std::vector<std::pair<int, int>> & snakeBody, SDL_Renderer* Renderer);
    void draw_fruit(SDL_Renderer *renderer) const;
    friend class Game;
    bool checkPosition(std::vector<std::pair<int, int>>& snakeBody);
private:
    Position fruit_position;
    SDL_Color fruit_color;
};

#endif //SNAKEGAME_FRUIT_H

