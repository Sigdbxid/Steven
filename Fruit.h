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
    Fruit(int x, int y) : fruit_position{x, y} {fruit_color = {0,0,255,255};} //设置初始颜色和位置
    void getFruit_Position(int HeadSnake_x, int HeadSnake_y, SDL_Renderer* Renderer);
    void draw_fruit(SDL_Renderer *renderer) const;
    friend class Game;
    [[nodiscard]] bool checkPosition(int HeadSnake_x, int HeadSnake_y) const;
private:
    Position fruit_position;
    SDL_Color fruit_color{};
};

#endif //SNAKEGAME_FRUIT_H

