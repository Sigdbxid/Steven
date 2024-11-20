//
// Created by Steven_NIUBI on 2024/11/1->
//

#ifndef SNAKEGAME_GAME_H
#define SNAKEGAME_GAME_H

#include <SDL.h>
class Fruit;
class Snake;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SQUARE_SIZE = 20;
const int FPS = 60;
const int FRAME_TIME = 1000 / FPS;

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
};
const Direct_vector UP = {0, -1};
const Direct_vector DOWN = {0, 1};
const Direct_vector LEFT = {-1, 0};
const Direct_vector RIGHT = {1, 0};
class Game {
public:
    Game();
    ~Game();
    void initialise();
    void handleInput();
    void reset();
    void resume();
    friend class Fruit;
    Snake* snake;
    Fruit* fruit;
    friend class Fruit;
private:
    bool IsGameOver();
    [[nodiscard]]bool checkCollision() const;
    bool isRunning;
    [[nodiscard]] bool win() const;
protected:
    int score; //得分
    SDL_Window* window = nullptr; //窗口
    SDL_Renderer* renderer = nullptr; //渲染器
    SDL_Event event; //事件
    Direct_vector direction;
    Uint32 frame_start, frame_time;
};

#endif //SNAKEGAME_GAME_H

