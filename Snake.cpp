//
// Created by Sandra Loja on 2024/11/1.
//

#include "Snake.h"

void Snake::snake_direction(SDL_Event* event, Direct_vector& direction)
{
//判断用户是否改变了蛇的方向
    if(event != nullptr) {
        if (event->type == SDL_KEYDOWN) //如果用户改变了蛇的方向
        {//判断蛇改变之后的方向
            switch (event->key.keysym.sym) {
                case SDLK_UP:
                    if (direction.y != 1) direction = UP;
                    break;
                case SDLK_DOWN:
                    if (direction.y != -1) direction = DOWN;
                    break;
                case SDLK_LEFT:
                    if (direction.x != 1) direction = LEFT;
                    break;
                case SDLK_RIGHT:
                    if (direction.x != -1) direction = RIGHT;
                    break;
            }
        }
    }
}
void Snake::snake_move(Direct_vector direction)
{
    HeadSnake_x += direction.x;
    HeadSnake_y += direction.y;
    snakeBody.insert(snakeBody.begin(), {HeadSnake_x, HeadSnake_y});
    snakeBody.pop_back();
#ifdef TEST
    std::cout << "snakeBody size: " << snakeBody.size() << std::endl;
    std::cout << "first snakeBody: " << snakeBody[0].first << ";" << snakeBody[0].second << std::endl;
    std::cout << "HeadSnake_x: " << HeadSnake_x << "; HeadSnake_y: " << HeadSnake_y << std::endl;
#endif
}
void Snake::snake_Grow(Direct_vector direction)
{
    auto tail = snakeBody.back();
    snakeBody.emplace_back(tail.first + direction.x, tail.second + direction.y);
    tailLength++;
}
void Snake::draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    for (auto &segment : snakeBody) {
        SDL_Rect rect = {segment.first * 20, segment.second * 20, 20, 20};
        SDL_RenderFillRect(renderer, &rect);
    }
}
