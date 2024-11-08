//
// Created by Steven NIUbi on 2024/11/1.
//

#ifndef SNAKEGAME_SNAKE_H
#define SNAKEGAME_SNAKE_H
#include <vector>
#include "Game.h"

class Snake{
public:
    void snake_Grow(Direct_vector direction);
    void snake_Move(SDL_Event* event, Direct_vector direction);
    void draw(SDL_Renderer* renderer);
    std::vector<std::pair<int, int>> snakeBody; // 蛇身坐标（不包括蛇头）
    friend class Game;
private:
    int HeadSnake_x, HeadSnake_y;
    int score;
    int tailLength;
};


#endif //SNAKEGAME_SNAKE_H