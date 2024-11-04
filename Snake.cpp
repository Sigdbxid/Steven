//
// Created by Sandra Loja on 2024/11/1.
//

#include "Snake.h"

void Snake::snake_Move() {
//判断用户是否改变了蛇的方向
    if(!(event.type == SDL_KEYDOWN))
    {
        /*蛇头坐标与当前的方向向量相加，确定下一时刻蛇头的位置*/
        HeadSnake_x += direction.x;
        HeadSnake_y += direction.y;
        snakeBody.insert(snakeBody.begin(),{HeadSnake_x,HeadSnake_y});//将蛇尾插入到蛇身列表的开头
        snakeBody.pop_back();
    }
    else //如果用户改变了蛇的方向
    {//判断蛇改变之后的方向
        switch (event.key.keysym.sym)
        {
            case SDLK_UP:
                if (direction.y != 1) direction = UP;
                break;
            case SDLK_DOWN:
                if (direction.y != -1) direction = DOWN;
                break;
            case SDLK_LEFT:
                if(direction.x != 1) direction = LEFT;
                break;
            case SDLK_RIGHT:
                if(direction.x != -1) direction = RIGHT;
                break;
        }
        /*确定转向后蛇头的位置，并将蛇尾放在蛇身最前面*/
        HeadSnake_x += direction.x;
        HeadSnake_y += direction.y;
        snakeBody.insert(snakeBody.begin(),{HeadSnake_x,HeadSnake_y});
        snakeBody.pop_back();
    }
}
void Snake::snake_Grow()
{
    HeadSnake_x += direction.x;
    HeadSnake_y += direction.y;
    snakeBody.insert(snakeBody.begin(),{HeadSnake_x,HeadSnake_y});
    tailLength++;
}
void Snake::draw()
{
    for(auto &bodyPart : snakeBody)
    {
        SDL_Rect rect = {bodyPart.first * SQUARE_SIZE,bodyPart.second * SQUARE_SIZE,
                         SQUARE_SIZE,SQUARE_SIZE};
        SDL_RenderFillRect(renderer,&rect);
    }
}

