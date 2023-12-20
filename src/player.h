#pragma once

#include "ball.h"


class PlayerPaddle
{
    public:
    float x ,y;
    float width , height;
    int speed;

    //draw player paddle
    void DrawPlayerPaddle()
    {
        DrawRectangle(x,y , width, height, WHITE );
    }

};