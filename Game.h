//
// Created by Steven_NIUBI on 2024/11/1.
//

#ifndef SNAKEGAME_GAME_H
#define SNAKEGAME_GAME_H
#include <SDL.h>
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SQUARE_SIZE = 20;
const int WIDTH_MAP = 30;
const int HEIGHT_MAP = 30;
class Game {
public:
    Game();
    ~Game();
    void start();
    void end();
    void handleInput();
    void reset();
    void resume();
    void gameOver();
    void win();
private:
    void setScore(int score);
    int getScore();
    void setHighScore(int highScore);
    int getHighScore();
    void setLevel(int level);
    int getLevel();
    void setSpeed(int speed);
    int getSpeed();
    void setDirection(int direction);
    int getDirection();
protected:
    int score; //得分
    SDL_Window* window = nullptr; //窗口
    SDL_Renderer* renderer = nullptr; //渲染器
    SDL_Event event; //事件
};


#endif //SNAKEGAME_GAME_H
