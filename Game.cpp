//
// Created by Steven NIUBI on 2024/11/1.
//
#include <iostream>
#include "Game.h"

Game::Game() : event(), score(0), level(0), speed(0)
{
    if(!SDL_Init(SDL_INIT_EVERYTHING)) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
    }
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    isrunning = true;
    direction = RIGHT;
}
Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void Game::handleInput()
{
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            isrunning = false;
        }
        else if(!IsgameOver())
        {
            reset();
            snake_Move();
        }
    }
}
void Game::reset()
{
    if(snake.HeadSnake_x == fruit.fruit_position.x
    && snake.HeadSnake_y == fruit.fruit_position.y)
    {
        getFruit_Position();
        snake.snake_Grow();
        score++;
    }
    else if(fruit.fruit_position.x == -1 && fruit.fruit_position.y == -1)
    {
        getFruit_Position();
    }
}
bool Game::IsgameOver()
{
    if(snake.HeadSnake_x < 0 || snake.HeadSnake_y < 0 || snake.HeadSnake_x > SCREEN_WIDTH || snake.HeadSnake_y > SCREEN_HEIGHT
    || (!checkCollision()) || win())
    {
        return true;
    }
    return false;
}
bool Game::checkCollision()
{
    for(const auto &segment : snake.snakeBody)
    {
        if(segment.second == snake.HeadSnake_x
        && segment.second == snake.HeadSnake_y)
            return true;
    }
    return false;
}
[[nodiscard]] bool Game::win() const
{
    if(snake.tailLength == (SCREEN_WIDTH / SQUARE_SIZE) * (SCREEN_HEIGHT / SQUARE_SIZE))
    {
        return true;
    }
    else
    {
        return false;
    }
}
