//
// Created by Steven NIUBI on 2024/11/1.
//
#include <iostream>
#include "Game.h"
#include <chrono>

Game::Game()
{
    if(!SDL_Init(SDL_INIT_EVERYTHING))    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
    }
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    /*生成随机数种子*/
    auto now = std::chrono::system_clock::now();
    auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    auto epoch = now_ms.time_since_epoch();
    auto value = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);
    auto seed = static_cast<unsigned int>(value.count());
    score = 0;
}
Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void handleInput()
{

}
void reset()
{

}
void resume()
{

}

void gameOver()
{

}
void win()
{

}
