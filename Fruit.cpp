//
// Created by Steven NIUBI on 2024/11/2.
//

#include "Fruit.h"
void Fruit::getFruit_Position()
{
    fruit_position.x = rand()% WIDTH_MAP;
    fruit_position.y = rand()% HEIGHT_MAP;

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