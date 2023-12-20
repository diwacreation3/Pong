#include "ball.h"

void Ball::DrawBall()
{
        DrawCircle(x, y,radius, WHITE);

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

        if(x + radius >= GetScreenWidth() || x- radius <= 0)
        {
            speed_x *= -1;
        }
}
