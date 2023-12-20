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

    void updatePlayer()
    {
        if(IsKeyDown(KEY_UP))
        {
            y = y - speed;
        }
        if (IsKeyDown(KEY_DOWN))
        {
            y = y + speed;
        }
    }

};