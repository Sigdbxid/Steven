//
// Created by Steven NIUBI on 2024/11/1.
//
#include <iostream>
#include "Game.h"
#include "Snake.h"
#include "Fruit.h"

Game::Game() : score(0), direction(RIGHT), snake(new Snake()), fruit(new Fruit(-1,-1))
{
    if (snake == nullptr || fruit == nullptr) {
        std::cerr << "Snake or Fruit pointer is not initialized." << std::endl;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING)) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
    }
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    isRunning = true;
    initialise();
}
Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void Game::resume()
{

    while(SDL_PollEvent(&event))
    {
        frame_start = SDL_GetTicks();
        if(!isRunning)
        {
            break;
        }
        handleInput();
        SDL_RenderClear(renderer);
        frame_time = SDL_GetTicks();
        if(FRAME_TIME > frame_time - frame_start)
        {
            SDL_Delay(FRAME_TIME - (frame_time - frame_start));
        }
    }
}
void Game::handleInput()
{
    if(event.type == SDL_QUIT || IsGameOver())
    {
        isRunning = false;
    }
    else if(!IsGameOver())
    {
        reset();
        snake->snake_Move(&event,direction);
    }
}
void Game::reset()
{
    if(snake->HeadSnake_x == fruit->fruit_position.x
    && snake->HeadSnake_y == fruit->fruit_position.y)
    {
        fruit->getFruit_Position(snake->snakeBody, renderer);
        fruit->draw_fruit(renderer);
        snake->snake_Grow(direction);
        score++;
    }
    else if(fruit->fruit_position.x == -1 && fruit->fruit_position.y == -1)
    {
        fruit->getFruit_Position(snake->snakeBody,renderer);
    }
}
bool Game::IsGameOver()
{
    if(snake->HeadSnake_x < 0 || snake->HeadSnake_y < 0 || snake->HeadSnake_x > SCREEN_WIDTH ||
    snake->HeadSnake_y > SCREEN_HEIGHT || (!checkCollision()) || win())
    {
        return true;
    }
    return false;
}
bool Game::checkCollision() const
{
    for(const auto &segment : snake->snakeBody)
    {
        if(segment.first == snake->HeadSnake_x
        && segment.second == snake->HeadSnake_y)
            return true;
    }
    return false;
}
[[nodiscard]] bool Game::win() const
{
    return snake->tailLength == (SCREEN_WIDTH / SQUARE_SIZE) * (SCREEN_HEIGHT / SQUARE_SIZE);
}
void Game::initialise()
{
    snake->HeadSnake_x = (SCREEN_WIDTH/2) * SQUARE_SIZE;
    snake->HeadSnake_y = (SCREEN_HEIGHT/2) * SQUARE_SIZE;
    snake->tailLength = 1;
}

