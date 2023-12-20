#include "ai-paddle.h"

using namespace std;

Color Green = Color{38, 186, 156, 255};
Color DarkGreen = Color{20, 160, 133, 255};
Color LightGreen = Color{129, 204, 184, 255};

Ball ball;
PlayerPaddle player;
playerAi opponent;

void game();

// set screen width height and title
const int screenWidth = 1080;
const int screenHeight = 800;
const char _title[20] = {"Pong"};
int main()
{
    bool gameState ;
    cout << "Starting the game " << endl;

    // initilize window
    InitWindow(screenWidth, screenHeight, _title);
    SetTargetFPS(60);

    // ball properties
    ball.radius = 20;
    ball.x = screenWidth / 2;
    ball.y = screenHeight / 2;
    ball.speed_x = 7;
    ball.speed_y = 7;

    // player properties
    player.width = 25;
    player.height = 120;
    player.x = screenWidth - player.width - 10;
    player.y = screenHeight / 2 - player.height / 2;
    player.speed = 9;

    // opponent ai properties
    opponent.height = 120;
    opponent.width = 25;
    opponent.x = 3;
    opponent.y = screenHeight / 2 - opponent.height / 2;
    opponent.speed = 6;

    // main game loop
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        if(gameState == false)
        {
          DrawText("Press Enter To Play Game", screenWidth /3, screenHeight /2 , 30, RAYWHITE);   
        }
        if(IsKeyPressed(KEY_ENTER))
        {
            gameState = true;
        }

        ClearBackground(Green);

        if(gameState == true)
        {
          game();   
        }
        
        if (ball.opponentScore == 10)
        {
            DrawText("AI Won ", screenWidth / 2.5, screenHeight / 3, 80, WHITE);
            gameState = false; 
        }
        if(ball.playerScore == 10)
        {
          DrawText("You Won ", screenWidth / 2.5, screenHeight / 3, 80, WHITE);
            gameState = false;  
        }

        EndDrawing();
    }

    // close window
    CloseWindow();
    return 0;
}
void game()
{
    // update
    ball.UpdateBall();
    player.updatePlayer();
    opponent.updateAi(ball.y);

    // checking for collision
    if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height}))
    {
        ball.speed_x *= -1;
    }

    // ball collision for Ai
    if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{opponent.x, opponent.y, opponent.width, opponent.height}))
    {
        ball.speed_x *= -1;
    }

    // Drawing
    ClearBackground(DarkGreen);
    DrawRectangle(screenWidth / 2, 0, screenWidth / 2, screenHeight, Green);
    DrawCircle(screenWidth / 2, screenHeight / 2, 150, LightGreen);
    // Draw center line
    DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);
    ball.DrawBall();

    opponent.DrawPaddle();
    player.DrawPaddle();

    DrawText(TextFormat("%i", ball.opponentScore), screenWidth / 4 - 20, 20, 80, WHITE);
    DrawText(TextFormat("%i", ball.playerScore), 3 * screenWidth / 4 - 20, 20, 80, WHITE);
}