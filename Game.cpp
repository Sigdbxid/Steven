//
// Created by Steven NIUBI on 2024/11/1.
//
#include <iostream>
#include <SDL_ttf.h>
#include "Game.h"
#include "Snake.h"
#include "Fruit.h"
//#define TEST
Game::Game() : score(0), direction(RIGHT), snake(new Snake()), fruit(new Fruit(-1,-1))
{
    if(SDL_Init(SDL_INIT_EVERYTHING)) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
    }
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    isRunning = true;
    snake->HeadSnake_x = (SCREEN_WIDTH/(2 * SQUARE_SIZE));
    snake->HeadSnake_y = (SCREEN_HEIGHT/(2 * SQUARE_SIZE));
    snake->snakeBody.resize(1);
    snake->snakeBody[0].first = snake->HeadSnake_x;
    snake->snakeBody[0].second = snake->HeadSnake_y;
    snake->tailLength = 1;
    snake->snake_color = {0, 255, 0, 255};
    fruit->getFruit_Position(snake->HeadSnake_x,snake->HeadSnake_y, renderer);
    TTF_Init();
}
Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    delete snake;
    delete fruit;
    SDL_Quit();
}
void Game::resume()
{
    Uint32 lastMoveTime = SDL_GetTicks(); // 记录上次移动时间
    const Uint32 MOVE_INTERVAL = 200; // 蛇移动间隔，单位：毫秒
    while(isRunning)
    {
        frame_start = SDL_GetTicks();
        while (SDL_PollEvent(&event)) {
            snake->snake_direction(&event,direction);
        }
        isRunning = IsGameOver();
        Uint32 currentTime = SDL_GetTicks();
        if (currentTime - lastMoveTime >= MOVE_INTERVAL) {
            snake->snake_move(direction); // 自动移动蛇
            reset(); // 检查蛇是否吃到果子
            lastMoveTime = currentTime; // 更新最后移动时间
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 250);
        SDL_RenderClear(renderer);
        snake->draw(renderer);
        fruit->draw_fruit(renderer);
        SDL_RenderPresent(renderer);
        frame_time = SDL_GetTicks();
        if (FRAME_TIME > frame_time - frame_start) {
            SDL_Delay(FRAME_TIME - (frame_time - frame_start));
        }
    }
}
void Game::reset()
{
    if(snake->HeadSnake_x == fruit->fruit_position.x
    && snake->HeadSnake_y == fruit->fruit_position.y)
    {
        fruit->getFruit_Position(snake->HeadSnake_x,snake->HeadSnake_y, renderer);
        snake->snake_Grow(direction);
        score++;
    }
}
bool Game::IsGameOver()
{
    if(snake->HeadSnake_x < 0 || snake->HeadSnake_y < 0 || snake->HeadSnake_x > SCREEN_WIDTH/SQUARE_SIZE ||
    snake->HeadSnake_y > SCREEN_HEIGHT/SQUARE_SIZE || checkCollision() || win())
    {
#ifdef TEST
        std::cout << "Game Over" << std::endl;
#endif
        return false;
    }
    return true;
}
bool Game::checkCollision() const
{
    for(size_t i = 1; i < snake->snakeBody.size(); i++)
    {
        if(snake->snakeBody[i].first == snake->HeadSnake_x
        && snake->snakeBody[i].second == snake->HeadSnake_y)
        {
#ifdef TEST
            std::cout << "Game Over2" << std::endl;
            std::cout << (snake->snakeBody[i].first) << "," << (snake->snakeBody[i].second) << std::endl;
            std::cout << (snake->HeadSnake_x) << "," << (snake->HeadSnake_y) << std::endl;
            std::cout << i <<std::endl;
#endif
            return true;
        }
    }
    return false;
}
bool Game::win() const
{
#ifdef TEST
    if(snake->tailLength == (SCREEN_WIDTH / SQUARE_SIZE) * (SCREEN_HEIGHT / SQUARE_SIZE))
        std::cout << "Game Over1" << std::endl;
#endif
    return snake->tailLength == (SCREEN_WIDTH / SQUARE_SIZE) * (SCREEN_HEIGHT / SQUARE_SIZE);
}
/*void Game::Write(std::string str, SDL_Rect *rect)
{
    SDL_Surface* surface = TTF_RenderText_Solid(font, str.c_str(), {0, 0, 0, 0});
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, texture, NULL, rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}*/
