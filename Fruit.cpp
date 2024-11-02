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
