#pragma once
#include "raylib.h"
#include <iostream>

class Ball
{
    public:
    float x ,y;
    int speed_x, speed_y;
    int radius;

    void DrawBall()
    {
        DrawCircle(x, y,radius, WHITE);
    }

    void UpdateBall()
    {
        x += speed_x;
        y += speed_y;
        
        //Window collison
        if(y + radius >= GetScreenHeight() || y - radius <= 0)
        {
            speed_y *= -1;
        }

        if(x + radius >= GetScreenWidth() || x- radius <= 0)
        {
            speed_x *= -1;
        }
    }

};