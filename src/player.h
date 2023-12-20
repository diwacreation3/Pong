#pragma once

#include "ball.h"


class PlayerPaddle
{
    public:
    float x ,y;
    float width , height;
    int speed;

    //draw player paddle
    void DrawPaddle();
    
    //update player position 
    void updatePlayer();

};