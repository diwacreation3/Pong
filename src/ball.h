#pragma once
#include "raylib.h"
#include <iostream>

class Ball
{
    public:
    float x ,y;
    int speed_x, speed_y;
    int radius;
    
    //Draw ball
    void DrawBall();

    // update ball position
    void UpdateBall();

};