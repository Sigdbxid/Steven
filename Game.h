//
// Created by Steven_NIUBI on 2024/11/1.
//

#ifndef SNAKEGAME_GAME_H
#define SNAKEGAME_GAME_H
#include <SDL.h>
#include "Snake.h"
#include "Fruit.h"
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SQUARE_SIZE = 20;
const int WIDTH_MAP = 30;
const int HEIGHT_MAP = 30;
struct Direct_vector {//方向向量
    int x;
    int y;
    Direct_vector& operator=(const Direct_vector &other)//重载赋值运算符,防止浅拷贝
    {// 运算符重载型参是不可改变的
        if(this != &other)
        {
            this->x = other.x;
            this->y = other.y;
        }
        return *this;
    }
}UP = {0,1}, DOWN = {0,-1}, LEFT = {-1,0}, RIGHT = {1,0};
class Game {
public:
    Game();
    ~Game();
    void handleInput();
    void reset();
    void resume();
private:
    bool IsGameOver();
    bool checkCollision();
    bool isrunning;
    [[nodiscard]] bool win() const;
protected:
    int score; //得分
    SDL_Window* window = nullptr; //窗口
    SDL_Renderer* renderer = nullptr; //渲染器
    SDL_Event event; //事件
    Snake snake;
    Fruit fruit{-1,-1};
    SDL_Color Background_color = {0, 0, 0, 255};
    int level;
    int speed;
    Direct_vector direction;
};


#endif //SNAKEGAME_GAME_H
