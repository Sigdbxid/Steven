//
// Created by Steven NIUbi on 2024/11/1.
//

#ifndef SNAKEGAME_SNAKE_H
#define SNAKEGAME_SNAKE_H
#include "Game.h"
#include <stdbool.h>
#include <vector>

class Snake : public Game{
public:
    Snake();
    void draw();
    void snake_Grow();
    void snake_Die();
    void snake_Move();
private:
    int HeadSnake_x, HeadSnake_y;
    int score;
    std::vector<std::pair<int, int>> snakeBody; // 蛇身坐标（不包括蛇头）
    int tailLength;
    struct Direct_vector {//方向向量
        int x;
        int y;
        Direct_vector operator=(Direct_vector &other)//重载赋值运算符,防止浅拷贝
        {
            if(this != &other)
            {
                this->x = other.x;
                this->y = other.y;
            }
            return *this;
        }
    }UP = {0,1}, DOWN = {0,-1}, LEFT = {-1,0}, RIGHT = {1,0};
    Direct_vector direction;
    int level;
    int speed;
};


#endif //SNAKEGAME_SNAKE_H