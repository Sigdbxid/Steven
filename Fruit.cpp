//
// Created by Steven NIUBI on 2024/11/2.
//

#include "Fruit.h"
void Fruit::getFruit_Position()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> xDis(0, SCREEN_WIDTH/SQUARE_SIZE - 1);
    std::uniform_int_distribution<> yDis(0, SCREEN_HEIGHT/SQUARE_SIZE - 1);
    do {
        fruit_position.x = xDis(gen);
        fruit_position.y = yDis(gen);
    } while (checkPosition());
    draw_fruit();
}
Fruit::Fruit(int x, int y)
{
    fruit_position.x = x;
    fruit_position.y = y;
    fruit_color = {100,0,0,255};
}
void Fruit::draw_fruit()
{
    SDL_Rect fruit_rect = {fruit_position.x * SQUARE_SIZE, fruit_position.y * SQUARE_SIZE,
                           SQUARE_SIZE, SQUARE_SIZE};
    SDL_SetRenderDrawColor(renderer, fruit_color.r, fruit_color.g, fruit_color.b, fruit_color.a);
    SDL_RenderFillRect(renderer, &fruit_rect);
}
bool Fruit::checkPosition()
{
    for(const auto& segment : snake.snakeBody)
    {
        if(segment.first == fruit_position.x && segment.second == fruit_position.y)
        {
            return true;
        }
    }
    return false;
}

