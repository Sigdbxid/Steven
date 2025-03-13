//
// Created by Steven NIUBI on 2024/11/2.
//

#include "Fruit.h"

void Fruit::getFruit_Position(int HeadSnake_x, int HeadSnake_y, SDL_Renderer* Renderer)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> xDis(0, SCREEN_WIDTH/SQUARE_SIZE - 1);
    std::uniform_int_distribution<> yDis(0, SCREEN_HEIGHT/SQUARE_SIZE - 1);
    do {
        fruit_position.x = xDis(gen);
        fruit_position.y = yDis(gen);
    } while (checkPosition(HeadSnake_x,HeadSnake_y));
}
void Fruit::draw_fruit(SDL_Renderer* renderer) const
{
    SDL_Rect fruit_rect = {fruit_position.x * SQUARE_SIZE, fruit_position.y * SQUARE_SIZE,
                           SQUARE_SIZE, SQUARE_SIZE};
    SDL_SetRenderDrawColor(renderer, fruit_color.r, fruit_color.g, fruit_color.b, fruit_color.a);
    SDL_RenderFillRect(renderer, &fruit_rect);
}
bool Fruit::checkPosition(int HeadSnake_x, int HeadSnake_y) const
{
    if(HeadSnake_x == fruit_position.x && HeadSnake_y == fruit_position.y)
        return true;
    return false;
}

