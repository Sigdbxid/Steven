//
// Created by Steven NIUbi on 2024/11/1.
//

#ifndef SNAKEGAME_SNAKE_H
#define SNAKEGAME_SNAKE_H
#include "Game.h"
#include <vector>

class Snake : public Game{
public:
    Snake();
    void draw();
    void snake_Grow();
    void snake_Move() override;
private:
    int HeadSnake_x, HeadSnake_y;
    int score;
    friend class Game;
    std::vector<std::pair<int, int>> snakeBody; // 蛇身坐标（不包括蛇头）
    int tailLength;
};


#endif //SNAKEGAME_SNAKE_H