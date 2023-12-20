#include "player.h"

void PlayerPaddle::LimitMovement()
{
    if (y <= 0)
    {
        y = 0;
    }

    if (y + height >= GetScreenHeight())
    {
        y = GetScreenHeight() - height;
    }
}

void PlayerPaddle::DrawPaddle()
{
    DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, WHITE);
}

void PlayerPaddle::updatePlayer()
{
    if (IsKeyDown(KEY_UP))
    {
        y = y - speed;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        y = y + speed;
    }

    LimitMovement();
}
