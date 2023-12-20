#include "ball.h"


void Ball::DrawBall()
{
        DrawCircle(x, y,radius, Yellow);

}

void Ball::UpdateBall()
{
     x += speed_x;
        y += speed_y;
        
        //Window collison
        if(y + radius >= GetScreenHeight() || y - radius <= 0)
        {
            speed_y *= -1;
        }

        if(x + radius >= GetScreenWidth()) //ai wins
        {
            opponentScore++;
            resetBall();
        }
        
        
         if( x- radius <= 0)
        {
            playerScore++;
            resetBall();
        }
}

void Ball::resetBall()
{
    x = GetScreenWidth() /2 ;
    y = GetScreenHeight() /2;

    int speedChoice[2] = {-1, 1};
    speed_x *= speedChoice[GetRandomValue(0,1)];
    speed_y *= speedChoice[GetRandomValue(0,1)];
}
