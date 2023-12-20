#pragma once
#include "raylib.h"

#include <iostream>

class Ball
{
    public:
    float x ,y;
    int speed_x, speed_y;
    int radius;
    Color Yellow = Color{243, 213, 154, 255};

    //score 
    int playerScore = 0;
    int opponentScore =0;
    
    //Draw ball
    void DrawBall();

    // update ball position
    void UpdateBall();

    //reset ball position 
    void resetBall();

};