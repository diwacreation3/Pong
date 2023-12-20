#include "player.h"

void PlayerPaddle::DrawPaddle()
{
    DrawRectangle(x,y , width, height, WHITE );

}

void PlayerPaddle::updatePlayer()
{
     if(IsKeyDown(KEY_UP))
        {
            y = y - speed;
        }
        if (IsKeyDown(KEY_DOWN))
        {
            y = y + speed;
        }

        if (y <= 0)
        {
            y =0;
        }

        if( y + height >= GetScreenHeight())
        {
            y = GetScreenHeight() - height;
        }
}
